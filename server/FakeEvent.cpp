//
// Created by piotr on 10.11.2019.
//

#include "FakeEvent.h"

#include <QRandomGenerator>

namespace server {

FakeEvent &FakeEvent::instance()
{
    static FakeEvent fakeEvent;
    return fakeEvent;
}

FakeEvent::FakeEvent()
    : secTimer()
    , logCollection()
{}

void FakeEvent::start()
{
    secTimer.setInterval(1000);
    secTimer.connect(&secTimer, &QTimer::timeout, this, &FakeEvent::cron1sec);
    secTimer.start();
}

void FakeEvent::cron1sec()
{
    QDateTime timestamp = QDateTime::currentDateTime();
    auto logPriority = static_cast<cm::LogPriority>(QRandomGenerator::global()->bounded(0, 10));
    cm::Message message = "msg-" + timestamp.toString("yyyyMMddhhmmss") + "/" + QString::number(logPriority);

    kolekcje obsłużyć za pomocą servisu
    logCollection.insert(timestamp, logPriority, message);
}

}