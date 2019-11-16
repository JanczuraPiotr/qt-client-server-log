//
// Created by piotr@janczura.pl on 2019.11.04
//

#ifndef COMMON_DB_SQLITESTRUCTURE_H
#define COMMON_DB_SQLITESTRUCTURE_H

#include <QSqlRecord>

#include "common/def.h"
#include "common/db/Structure.h"

namespace cm::db {

class SQLiteStructure : public Structure {
public:
    SQLiteStructure() = default;
    ~SQLiteStructure() override = default;

protected: // methods
    bool isLog() override;
    void initLog() override;
};

}


#endif //COMMON_DB_SQLITESTRUCTURE_H
