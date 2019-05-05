//
// Created by piotr@janczura.pl on 2019.04.18
//
#include "Driver.h"

#include <QtCore/QString>
#include "server/config.h"

namespace model::db {

Driver &Driver::i() {
    static Driver instance(Config::dbHost(), Config::dbName(), Config::dbUser(), Config::dbPassword());
    return instance;
}

Driver::Driver(const QString &host, const QString &dbName, const QString &dbUser, const QString &dbPassword)
        : db(QSqlDatabase::addDatabase("QMYSQL"))
{
    db.setHostName(host);
    db.setDatabaseName(dbName);
    db.setUserName(dbUser);
    db.setPassword(dbPassword);

    if (!db.open()) {
        qDebug() << db.lastError();
        qFatal("Failed to connect.");
    }
}

Driver::~Driver() = default;

}