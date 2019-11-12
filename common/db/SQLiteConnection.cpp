//
// Created by piotr@janczura.pl on 2019.11.04
//

#include "SQLiteConnection.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

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

cm::AutoId SQLiteConnection::insert(const QString &command, const cm::Params &params)
{
    sqlError_.setType(QSqlError::NoError);
    QSqlQuery query;
    query.prepare(command);
    for(auto &param : params) {
        query.bindValue(param.first, param.second);
    }
    if ( ! query.exec()) {
        sqlError_ = query.lastError();
        lastInsertId(0);
    } else {
        if (query.lastInsertId().isValid()) {
            lastInsertId(query.lastInsertId().toUInt());
        } else {
            lastInsertId(0);
        }
    }
    return lastInsertId_;
}

}