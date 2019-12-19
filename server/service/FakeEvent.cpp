//
// Created by piotr on 10.11.2019.
//

#include "FakeEvent.h"

#include <iostream>

#include <QRandomGenerator>
#include <QString>
#include <server/action/InsertLog.h>
#include <common/db/exception.h>

namespace sv {

FakeEvent &FakeEvent::instance()
{
    static FakeEvent fakeEvent;
    return fakeEvent;
}

FakeEvent::FakeEvent()
    : secTimer()
    , insertLog()
{}

void FakeEvent::start()
{
    secTimer.setInterval(3000);
    secTimer.connect(&secTimer, &QTimer::timeout, this, &FakeEvent::cron1sec);
    secTimer.start();
}

void FakeEvent::cron1sec()
{
    QDateTime timestamp = QDateTime::currentDateTime();
    auto logPriority = static_cast<cm::LogPriority>(QRandomGenerator::global()->bounded(0, 3));
    cm::Message message = "msg-" + timestamp.toString("yyyyMMddhhmmss") + "/" + QString::number(static_cast<short>(logPriority));

    try {

        insertLog.timestamp(timestamp);
        insertLog.logPriority(logPriority);
        insertLog.message(message);
        insertLog.make();

        qDebug() << "wygenerowano log =" << insertLog.id();
        emit insertedLog(
                insertLog.id()
                , insertLog.timestamp()
                , insertLog.logPriority()
                , insertLog.message()
                );

    } catch (cm::db::ex::General &ex) {
        std::cerr << ex.msg().toStdString();
    }

}

}