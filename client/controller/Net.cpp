//
// Created by piotr@janczura.pl on 2019.11.20
//

#include <client/model/LogCollection.h>
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

void Net::onTextMessageReceived(const QString &msg)
{
    QWebSocket *pSender = qobject_cast<QWebSocket *>(sender());
    QStringList tokens = msg.split("|");
    cm::NetCommand netCommand  = tokens[0];

    //cm::TCPPort port = pSender->peerPort();

    if (netCommand == "log") {
        cl::input::Log log;
        log.parse(tokens[1]);
        cl::model::LogCollection logCollection;
        logCollection.insert(
                log.getTimestamp()
                , log.getLogId()
                , log.getLogPriority()
                , log.getMessage()
                );
    } else{
        pSender->sendTextMessage(cm::output::ErrorMessage::badCommand(netCommand));
    }

    // rozpoznaj komendę
}

}