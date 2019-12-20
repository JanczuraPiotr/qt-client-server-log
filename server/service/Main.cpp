//
// Created by piotr@janczura.pl on 2019.12.17
//

#include "Main.h"
#include <QDebug>
#include <server/model/LogCollection.h>
#include <server/output/Log.h>

namespace sv::service {

Main& Main::instance() {
    static Main main;
    return main;
}


Main::Main()
{
}

void Main::getLogsAfter(const QDateTime &limit, cm::TCPPort clientsPort)
{
    qDebug() << __FILE__ << __LINE__ << "odebrano komendę : getLogsAfter" << limit;
    model::LogCollection logCollection;
    auto logs = logCollection.getLogsAfter(limit);
    sv::output::Log output;
    auto jsonString = output.map(logs);
    emit messageToClient("getLogsAfter|" + jsonString, clientsPort);
}

void Main::getLogsBefore(const QDateTime &limit, cm::TCPPort clientsPort)
{
    qDebug() << __FILE__ << __LINE__ << "odebrano komendę : getLogsBefore" << limit;
    model::LogCollection logCollection;
    auto logs = logCollection.getLogsBefore(limit);
    sv::output::Log output;
    auto jsonString = output.map(logs);
    emit messageToClient("getLogsBefore|" + jsonString, clientsPort);
}

void Main::getLogsBetween(const QDateTime &limitEarlier, const QDateTime &limitLatter, cm::TCPPort clientsPort)
{
    qDebug() << __FILE__ << __LINE__ << "odebrano komendę : getLogsBetween" << limitEarlier << limitLatter;
    model::LogCollection logCollection;
    auto logs = logCollection.getLogsBetween(limitEarlier, limitLatter);
    sv::output::Log output;
    auto jsonString = output.map(logs);
    emit messageToClient("getLogsBetween|" + jsonString, clientsPort);
}


}