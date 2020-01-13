//
// Created by piotr@janczura.pl on 2019.11.20
//

#include "client/model/LogCollection.h"
#include "common/output/ErrorMessage.h"
#include "client/input/Log.h"
#include "client/input/GetLogsBetween.h"
#include "Net.h"

namespace cl::controller {

Net::Net(const QString &url, cm::TCPPort serverIPPort)
    : url_(url)
    , serverIPPort_(serverIPPort)
    , socket_()
    , connected_(false)
    , tries_(0)
    , lastConnectionAttempt_(QDateTime::fromTime_t(0))
{
    openSocket();
    connect(&socket_, &QWebSocket::connected, this, &Net::onConnected);
    connect(&socket_, &QWebSocket::disconnected, this, &Net::onDisconnected);
    connect(&socket_, &QWebSocket::textMessageReceived, this, &Net::onTextMessageReceived);
}

Net::~Net()
{
    socket_.close();
}

void Net::netCommand(const cm::NetCommand &command)
{
    socket_.sendTextMessage(command);
}


void Net::onConnected()
{
    connected_ = true;
}

void Net::onDisconnected()
{
    connected_ = false;
}

void Net::openSocket()
{
    // @task przetestować, uruchomić, naprawić ... łączenie pracującego klienta do startującego serwera
    if (lastConnectionAttempt_.toMSecsSinceEpoch() + cm::RECONNECT_TIME_IN_MILLISECONDS < QDateTime::currentDateTime().toMSecsSinceEpoch())
    {
        if(tries_++ >= cm::MAX_RECONNECT_ATTEMPTS)
        {
            qDebug() << __FILE__ << __LINE__;
            // throw jakiś exception
        } else {
            qDebug() << __FILE__ << __LINE__;
        }

        qDebug() << __FILE__ << __LINE__ << QUrl(url_ + ":" + QString::number(serverIPPort_));
        socket_.open(QUrl(url_ + ":" + QString::number(serverIPPort_)));
        lastConnectionAttempt_ = QDateTime::currentDateTime();
        if (socket_.isValid()) {
            qDebug() << __FILE__ << __LINE__;
        }
    } else {
        qDebug() << __FILE__ << __LINE__;
    }
}

void Net::onTextMessageReceived(const cm::NetInput &netInput)
{
    cm::Index lim = netInput.indexOf("|");
    cm::NetCommand command = netInput.left(lim);

    if (lim == cm::IndexInfinity || command.isEmpty()) {
        socket_.sendTextMessage(cm::output::ErrorMessage::badCommand(command));
    } else {
        if (command == "log") {
            cl::input::Log input(netInput, lim + 1);
            if (input.parse()) {
                emit log(input.getId(), input.getTimestamp(), input.getPriority(), input.getMessage());
            } else {
                // @task obsłużyć błąd struktury danych wejściowych
                qDebug() << "// @task obsłużyć błąd struktury danych wejściowych";
            }
        } else if (command == "getLogsBetween") {
            cl::input::GetLogsBetween input(netInput);
            if (input.parse()) {
                //emit log(input.getId(), inputLog.getTimestamp(), inputLog.getPriority(), inputLog.getMessage());
                emit logsBetween(input.getBorderEarlier(), input.getBorderLatter(), input.getLogCollection());
            } else {
                // @task obsłużyć błąd struktury danych wejściowych
                qDebug() << "// @task obsłużyć błąd struktury danych wejściowych";
            }
        } else{
            socket_.sendTextMessage(cm::output::ErrorMessage::badCommand(command));
        }
    }



    // rozpoznaj komendę
}

}