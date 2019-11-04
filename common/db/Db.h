//
// Created by piotr@janczura.pl on 2019.07.06
//

#ifndef CM_DB_DB_H
#define CM_DB_DB_H

#include <QString>
#include <QSqlDatabase>

#include "common/db/Structure.h"
#include "common/db/Connection.h"
#include "common/db/SQLiteConnection.h"

namespace cm::db {

class Db {
public:

    static bool init(
            QString dbHost
            , cm::TCPPort dbPort
            , QString dbType
            , QString dbName
            , QString dbUser
            , QString dbPass);
    static void close();

    virtual ~Db();

    static Structure *structure();
    static Connection *connection();

protected:

    static Structure *structure_;
    static Connection *connection_;

private:
    Db() = default;

};

}


#endif //CM_DB_DB_H
