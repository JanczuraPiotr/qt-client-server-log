//
// Created by piotr@janczura.pl on 2019.04.18
//

#ifndef QT_LOG_DRIVER_H
#define QT_LOG_DRIVER_H

#include <QtSql>
#include <QSqlDatabase>

namespace model::db {

class Driver {
public:

    static Driver& i();
    virtual ~Driver();

    QSqlDatabase &res();

private:
    Driver(const QString& host, const QString& dbName, const QString& dbUser, const QString& dbPassword);

    QSqlDatabase db;
};

}

#endif //QT_LOG_DRIVER_H
