//
// Created by piotr@janczura.pl on 2019.11.04
//

#ifndef QT_CLIENT_SERVER_LOG_SQLITESTRUCTURE_H
#define QT_CLIENT_SERVER_LOG_SQLITESTRUCTURE_H

#include <QSqlRecord>

#include "common/def.h"
#include "common/db/Structure.h"

namespace cm::db {

class SQLiteStructure : public Structure {
public:
    SQLiteStructure() = default;
    ~SQLiteStructure() override = default;

    Params logParams() override;
    QSqlRecord logRecord() override ;


protected: // methods
    bool isLog() override;
    void initLog() override;
};

}


#endif //QT_CLIENT_SERVER_LOG_SQLITESTRUCTURE_H
