//
// Created by piotr@janczura.pl on 2019.11.04
//

#ifndef QT_CLIENT_SERVER_LOG_CONNECTION_H
#define QT_CLIENT_SERVER_LOG_CONNECTION_H

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlRecord>

#include "common/def.h"

namespace cm::db {

class Connection {
public:

    explicit Connection(
            QSqlDatabase database
            , const QString &dbHost
            , cm::TCPPort dbPort
            , const QString &dbName
            , const QString &dbUser
            , const QString &dbPass);

    virtual ~Connection() = default;

    virtual QSqlQuery execute(const QString &command) = 0;
    virtual cm::AutoId lastInsertId() = 0;
    void close();

    protected: // attributes

        QSqlDatabase database_;
        cm::AutoId lastInsertId_ = 0;
        QSqlError sqlError_;
        QString dbName_;

    };
}
#endif //QT_CLIENT_SERVER_LOG_CONNECTION_H
