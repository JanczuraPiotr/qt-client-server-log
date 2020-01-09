//
// Created by piotr@janczura.pl on 2019.11.20
//

#include "client/model/LogCollection.h"
#include "common/output/ErrorMessage.h"
#include "client/input/Log.h"
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
    qDebug() << __FILE__ << __LINE__;
    socket_.close();
}

void Net::onConnected()
{
    connected_ = true;
    qDebug() << __FILE__ << __LINE__;
}

void Net::onDisconnected()
{
    connected_ = false;
    qDebug() << __FILE__ << __LINE__;
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
    QWebSocket *pSender = qobject_cast<QWebSocket *>(sender());
    //qDebug() << "client odebrał wiadomość :" << netInput;
    cm::Index lim = netInput.indexOf("|");
    cm::NetCommand command = netInput.left(lim);

    if (lim == cm::IndexInfinity || command.isEmpty()) {
        pSender->sendTextMessage(cm::output::ErrorMessage::badCommand(command));
    } else {
        if (command == "log") {
            cl::input::Log inputLog(netInput, lim + 1);
            if (inputLog.parse()) {
                emit log(inputLog.getId(), inputLog.getTimestamp(), inputLog.getPriority(), inputLog.getMessage());
            } else {
                // @task obsłużyć błąd struktury danych wejściowych
                qDebug() << "// @task obsłużyć błąd struktury danych wejściowych";
            }
        } else{
            pSender->sendTextMessage(cm::output::ErrorMessage::badCommand(command));
        }
    }



    // rozpoznaj komendę
}

}