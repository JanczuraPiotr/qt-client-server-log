//
// Created by piotr@janczura.pl on 2019.11.12
//

#ifndef QT_CLIENT_SERVER_LOG_NETCONNECTION_H
#define QT_CLIENT_SERVER_LOG_NETCONNECTION_H

#include <QtCore/QObject>

#include "common/def.h"

namespace server::service {

class NetConnection : public QObject{
Q_OBJECT
public:
    static NetConnection &instance();

    void start();

public slots:

void insertedLog(
        cm::AutoId id
        , const QDateTime &dateTime
        , cm::LogPriority logPriority
        , const cm::Message &message);

private:

    explicit NetConnection();
};

}


#endif //QT_CLIENT_SERVER_LOG_NETCONNECTION_H
