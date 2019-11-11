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

virtual cm::AutoId insert(const QString &command, const cm::Params &params) = 0;
[[nodiscard]] virtual cm::AutoId lastInsertId();

void close() noexcept ;

protected: // methods

    virtual void lastInsertId(cm::AutoId lastInsertId);

protected: // attributes

    QSqlDatabase database_;
    QString dbName_;
    cm::AutoId lastInsertId_ = 0;
    QSqlError sqlError_;

};

}
#endif //QT_CLIENT_SERVER_LOG_CONNECTION_H
