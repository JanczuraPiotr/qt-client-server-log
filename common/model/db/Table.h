//
// Created by piotr@janczura.pl on 2019.04.21
//

#ifndef QT_LOG_TABLE_H
#define QT_LOG_TABLE_H

#include "common/model/db/Driver.h"
#include "common/model/db/Record.h"
#include "common/model/db/def.h"

namespace model::db {

class Table {
public:

    explicit Table(model::db::Driver &driver);
    virtual ~Table() = default;

protected:
    model::db::Driver &dbDriver;
};


}

#endif //QT_LOG_TABLE_H
