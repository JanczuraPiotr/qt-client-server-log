//
// Created by piotr@janczura.pl on 2019.07.06
//

#include <QSqlDatabase>

#include "common/db/Db.h"
#include "common/db/Connection.h"
#include "common/db/SQLiteConnection.h"
#include "common/db/SQLiteStructure.h"

namespace cm::db {


Structure *Db::structure_ = nullptr;
Connection *Db::connection_ = nullptr;

bool Db::init(
        QString dbHost
        , cm::TCPPort dbPort
        , QString dbType
        , QString dbName
        , QString dbUser
        , QString dbPass) {
    if (connection_ != nullptr) {
        return true;
    }
    if (dbType == "QSQLITE") {
        Db::connection_ = new SQLiteConnection(
                QSqlDatabase::addDatabase(dbType)
                , dbHost
                , dbPort
                , dbName
                , dbUser
                , dbPass);

        Db::structure_ = new SQLiteStructure();
        Db::structure_->initStructure();

        return true;
    } else {
        return false;
    }
}

Db::~Db() {
    Db::close();
}

void Db::close() {
//    if (Db::conn) {
//        Db::conn->close();
//
//        delete Db::conn;
//        delete Db::comm;
//        delete Db::def;
//        Db::conn = nullptr;
//    }
}

Connection *Db::connection()
{
    return Db::connection_;
}


Structure *Db::structure()
{
    return Db::structure_;
}

}