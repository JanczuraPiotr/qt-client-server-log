//
// Created by piotr@janczura.pl on 2019.11.12
//

#include "NetConnection.h"

#include <QDebug>

namespace server::service {

NetConnection &NetConnection::instance()
{
    static NetConnection netConnection;
    return netConnection;
}

NetConnection::NetConnection()
    : QObject(nullptr)
{

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
    qDebug() << "new log :" << id << dateTime << static_cast<short>(logPriority) << message;
}


}