//
// Created by piotr@janczura.pl on 10.11.2019.
//

#ifndef QT_CLIENT_SERVER_LOG_FAKEEVENT_H
#define QT_CLIENT_SERVER_LOG_FAKEEVENT_H

#include <QTimer>
#include <QObject>

#include "model/LogCollection.h"

namespace server {

class FakeEvent : public QObject {
    Q_OBJECT
public:
    static FakeEvent &instance();
    virtual ~FakeEvent() = default;

    void start();

public slots:

    void cron1sec();

private: // methods

    explicit FakeEvent();

private: // attributes

    QTimer secTimer;
    model::LogCollection logCollection;

};

}



#endif //QT_CLIENT_SERVER_LOG_FAKEEVENT_H
