//
// Created by piotr@janczura.pl on 2019.11.04
//

#ifndef COMMON_DB_SQLITECONNECTION_H
#define COMMON_DB_SQLITECONNECTION_H

#include "Connection.h"

#include <QVariant>

namespace cm::db {


class SQLiteConnection : public Connection {
public:

    explicit SQLiteConnection(
            const QSqlDatabase& database
            , const QString &dbHost
            , cm::TCPPort dbPort
            , const QString &dbName
            , const QString &dbUser
            , const QString &dbPass);

    [[nodiscard]] cm::AutoId insert(const QString &command, const cm::Params &params) override;

public: // lock

    SQLiteConnection() = delete;
    SQLiteConnection(const SQLiteConnection &) = delete;
    SQLiteConnection(SQLiteConnection &&) = delete;
    SQLiteConnection &operator = (const SQLiteConnection&) = delete;
    SQLiteConnection &operator = (SQLiteConnection &&) = delete;
};

}

#endif //COMMON_DB_SQLITECONNECTION_H
