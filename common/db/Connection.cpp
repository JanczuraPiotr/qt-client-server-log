//
// Created by piotr@janczura.pl on 2019.11.04
//

#include "Connection.h"

namespace cm::db {

Connection::Connection(
        QSqlDatabase database
        , const QString &dbHost
        , cm::TCPPort dbPort
        , const QString &dbName
        , const QString &dbUser
        , const QString &dbPass)
        : database_(database)
        , dbName_(dbName)
        , lastInsertId_(0)

{
    database.setDatabaseName(dbName);
    database.setHostName(dbHost);
    database.setPort(dbPort);
    database.setUserName(dbUser);
    database.setPassword(dbPass);
    database.open();
}

void Connection::close() noexcept
{
    database_.close();
    QSqlDatabase::removeDatabase(dbName_);
}

cm::AutoId Connection::lastInsertId()
{
    return lastInsertId_;
}

void Connection::lastInsertId(cm::AutoId lastInsertId)
{
     lastInsertId_ = lastInsertId;
}

}
