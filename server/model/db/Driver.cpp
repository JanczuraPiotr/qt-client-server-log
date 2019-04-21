//
// Created by piotr@janczura.pl on 2019.04.18
//
#include "Driver.h"

#include <QtCore/QString>
#include "server/config.h"

namespace sp9pj::model::db {

Driver &Driver::i() {
    static Driver instance(sp9pj::Config::dbHost(), sp9pj::Config::dbName(), sp9pj::Config::dbUser(), sp9pj::Config::dbPassword());
    return instance;x
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

QSqlDatabase &Driver::res() {
    return db;
}

Driver::~Driver() = default;

}