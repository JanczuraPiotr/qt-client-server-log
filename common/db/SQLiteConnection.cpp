//
// Created by piotr@janczura.pl on 2019.11.04
//

#include "SQLiteConnection.h"

#include <QSqlQuery>
#include <QSqlError>

namespace cm::db {

SQLiteConnection::SQLiteConnection(
        QSqlDatabase database
        , const QString &dbHost
        , cm::TCPPort dbPort
        , const QString &dbName
        , const QString &dbUser
        , const QString &dbPass)
        : Connection(database, dbHost, dbPort, dbName, dbUser, dbPass)
{

}

QSqlQuery SQLiteConnection::execute(const QString &command)
{
    sqlError_.setType(QSqlError::NoError);
    QSqlQuery query;
    query.prepare(command);
    if ( ! query.exec()) {
        sqlError_ = query.lastError();
        lastInsertId_ = 0;
    } else {
        if (query.lastInsertId().isValid()) {
            lastInsertId_ = query.lastInsertId().toULongLong();
        }
    }
    return query;
}

cm::AutoId SQLiteConnection::lastInsertId()
{
    return lastInsertId_;
}

}