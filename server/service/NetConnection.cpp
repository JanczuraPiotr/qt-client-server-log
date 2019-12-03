//
// Created by piotr@janczura.pl on 2019.11.12
//

#include "NetConnection.h"

#include <QDebug>
#include <QString>
#include <server/output/Log.h>

#include "server/app/ConfigFile.h"

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
    , socketsClients()
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
    output::Log log;
    broadcastToNet("log|" + log.json(id, dateTime, logPriority, message));
}

void NetConnection::broadcastToNet(const QString &msg)
{
    for (QWebSocket *pClient : qAsConst(socketsClients)) {
        pClient->sendTextMessage(msg);
    }
}

QString NetConnection::initialMessage()
{
    return "Podłączyłeś sie do LogServer";
}

void NetConnection::onNewConnection()
{
    auto pSocket = socketServer->nextPendingConnection();
    pSocket->setParent(this);

    connect(pSocket, &QWebSocket::textMessageReceived, this, &NetConnection::processMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &NetConnection::socketDisconnected);

    socketsClients.insert(pSocket->peerPort(), pSocket);
    pSocket->sendTextMessage(initialMessage());
}


void NetConnection::processMessage(const QString &msg)
{
    qDebug() << __FILE__ << __LINE__ << msg;
//    QWebSocket *pSender = qobject_cast<QWebSocket *>(sender());
//    QStringList tokens = msg.split("|");
}

void NetConnection::socketDisconnected()
{
    auto *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient) {
        socketsClients.remove(pClient->peerPort());
    }
}

}