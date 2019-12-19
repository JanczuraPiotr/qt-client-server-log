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

void Main::getLogsAfter(const QDateTime &borderMoment, cm::TCPPort clientsPort)
{
    qDebug() << __FILE__ << __LINE__ << "odebrano komendę : getLogsAfter" << borderMoment;
//    model::LogCollection logCollection;
//    auto logs = logCollection.getLogsAfter(borderMoment);
//    sv::output::Log output;
//    auto jsonString = output.map(logs);
}

void Main::getLogsBefore(const QDateTime &borderMoment, cm::TCPPort clientsPort)
{
//    qDebug() << __FILE__ << __LINE__ << "odebrano komendę : getLogsBefore" << borderMoment;
//    model::LogCollection logCollection;
//    auto logs = logCollection.getLogsBefore(borderMoment);
//    sv::output::Log output;
//    auto jsonString = output.map(logs);
}

void Main::getLogsBetween(const QDateTime &borderEarlier, const QDateTime &borderLatter, cm::TCPPort clientsPort)
{
    qDebug() << __FILE__ << __LINE__ << "odebrano komendę : getLogsBetween" << borderEarlier << borderLatter;
//    model::LogCollection logCollection;
//    auto logs = logCollection.getLogsBetween(borderEarlier, borderLatter);
//    sv::output::Log output;
//    auto jsonString = output.map(logs);
}


}