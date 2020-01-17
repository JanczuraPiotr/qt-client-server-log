//
// Created by piotr@janczura.pl on 2019.11.12
//

#include "NetConnection.h"

#include <QDebug>
#include <QString>

#include "server/app/ConfigFile.h"
#include "server/model/LogCollection.h"
#include "server/input/GetLogsBetween.h"
#include "server/output/Log.h"


namespace sv::service {

NetConnection &NetConnection::instance()
{
    static NetConnection netConnection;
    return netConnection;
}

NetConnection::NetConnection()
    : QObject(nullptr)
    , socketServer(new QWebSocketServer(QStringLiteral("Log Server"),
                                        QWebSocketServer::NonSecureMode,
                                        this))
    , netProtocol(cm::NetProtocol::JSON) // @work uruchomić możliwość wyboru protokołu
    , socketsClients()
    , logsListeners()

{
    cm::TCPPort port = ConfigFile::instance()->getServerPort();
    if (socketServer->listen(QHostAddress::Any, port)) {
        connect(socketServer, &QWebSocketServer::newConnection, this, &NetConnection::onNewConnection);
    }
}

NetConnection::~NetConnection()
{
    socketServer->close();
    delete socketServer;
}

void NetConnection::start()
{

}

void NetConnection::insertedLog(
            cm::AutoId id
            , const QDateTime &dateTime
            , cm::LogPriority logPriority
            , const cm::Message &message)
{
    qDebug() << "NetConnection::insertedLog";
    output::Log log(netProtocol);// @work uruchomić możliwość wyboru protokołu
    broadcastLogToNet(log.one(id, dateTime, logPriority, message));
}

void NetConnection::messageToClient(const QString &msg, cm::TCPPort clientsPort)
{
    qDebug() << "NetConnection::messageToClient" << msg;
    socketsClients[clientsPort]->sendTextMessage(msg);
    // @task obsłuż brak klienta
}

void NetConnection::broadcastToNet(const QString &msg)
{
    for (auto &it : socketsClients) {
        it.second->sendTextMessage(msg);
    }
}

void NetConnection::broadcastLogToNet(const QString &msg)
{
    for (auto &it : logsListeners) {
        socketsClients[it]->sendTextMessage("log|" + msg);
    }
}

QString NetConnection::initialMessage()
{
    return "Podłączyłeś sie do LogServer";
}

void NetConnection::onNewConnection()
{
    qDebug() << __FILE__ << __LINE__ << "NetConnection::onNewConnection()";
    auto pSocket = socketServer->nextPendingConnection();
    pSocket->setParent(this);

    connect(pSocket, &QWebSocket::textMessageReceived, this, &NetConnection::processMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &NetConnection::socketDisconnected);

    socketsClients.insert(std::make_pair(pSocket->peerPort(), pSocket));
    startPushingLogs(pSocket->peerPort());
    pSocket->sendTextMessage(initialMessage());
}

void NetConnection::stopPushingLogs(cm::TCPPort clientsPort)
{
    logsListeners.erase(std::find(logsListeners.begin(), logsListeners.end(), clientsPort));
}

void NetConnection::startPushingLogs(cm::TCPPort clientsPort)
{
    if (std::find(logsListeners.begin(), logsListeners.end(), clientsPort) == logsListeners.end()) {
        logsListeners.push_back(clientsPort);
    }
}

void NetConnection::processMessage(const cm::NetInput &netInput)
{
    QWebSocket *pSender = qobject_cast<QWebSocket *>(sender());
    cm::Index lim = netInput.indexOf("|");
    cm::NetCommand command = netInput.left(lim);
    qDebug() << "serwer odebrał wiadomość :" << netInput;
    // @task logowanie błędu przenieść do obsługi wyjątku

    if (lim == cm::IndexInfinity || command.isEmpty()) {
        sv::model::LogCollection logCollection;
        logCollection.insert(QDateTime(), cm::LogPriority::error, "bad command");
    } else {
        if (command == "getLogsBetween") {
            sv::input::GetLogsBetween input(cm::NetProtocol::JSON);// @work uruchomić możliwość wyboru protokołu
            if (input.parse(netInput, lim)) {
                emit getLogsBetween(input.getBorderEarlier(), input.getBorderLatter(), pSender->peerPort());
            } else {
                sv::model::LogCollection logCollection;
                logCollection.insert(QDateTime(), cm::LogPriority::error, "bad params for command : getLogsBetween");
            }

        } else if (command == "stopPushingLogs") {
            stopPushingLogs(pSender->peerPort());
            messageToClient("wyłączyłeś powiadomienia o nowych logach", pSender->peerPort());
        } else if (command == "startPushingLogs") {
            startPushingLogs(pSender->peerPort());
            messageToClient("włączyłeś powiadomienia o nowych logach", pSender->peerPort());
        } else {
            sv::model::LogCollection logCollection;
            logCollection.insert(QDateTime(), cm::LogPriority::error, "bad command");
        }
    }
}

void NetConnection::socketDisconnected()
{
    auto *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient) {
        stopPushingLogs(pClient->peerPort());
        socketsClients.erase(pClient->peerPort());
    }
}

}