//
// Created by piotr@janczura.pl on 2019.12.17
//

#include "Main.h"
#include <QDebug>

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
}

void Main::getLogsBefore(const QDateTime &borderMoment, cm::TCPPort clientsPort)
{
    qDebug() << __FILE__ << __LINE__ << "odebrano komendę : getLogsBefore" << borderMoment;
}

void Main::getLogsBetween(const QDateTime &borderEarlier, const QDateTime &borderLatter, cm::TCPPort clientsPort)
{
    qDebug() << __FILE__ << __LINE__ << "odebrano komendę : getLogsBetween" << borderEarlier << borderLatter;
}

void Main::stopPushingLogs(cm::TCPPort clientsPort)
{
    qDebug() << __FILE__ << __LINE__ << "odebrano komendę : stopPushingLogs";
}

void Main::startPushingLogs(cm::TCPPort clientsPort)
{
    qDebug() << __FILE__ << __LINE__ << "odebrano komendę : startPushingLogs";
}


}