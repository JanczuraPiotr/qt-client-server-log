//
// Created by piotr@janczura.pl on 10.11.2019.
//

#ifndef SERVER_FAKEEVENT_H
#define SERVER_FAKEEVENT_H

#include <QTimer>
#include <QObject>

#include "server/action/InsertLog.h"

namespace server {

class FakeEvent : public QObject {
    Q_OBJECT
public:
    static FakeEvent &instance();
    ~FakeEvent() override = default;

    void start();

public slots:

    void cron1sec();

signals:

    void insertedLog(
            cm::AutoId id
            , const QDateTime &dateTime
            , cm::LogPriority logPriority
            , const cm::Message &message);

private: // methods

    explicit FakeEvent();


private: // attributes

    QTimer secTimer;
    server::action::InsertLog insertLog;

public: // lock
    FakeEvent(const FakeEvent &) = delete;
    FakeEvent(FakeEvent &&) = delete;
    FakeEvent &operator = (const FakeEvent&) = delete;
    FakeEvent &operator = (FakeEvent &&) = delete;

};

}



#endif //SERVER_FAKEEVENT_H
