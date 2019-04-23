//
// Created by piotr@janczura.pl on 2019.04.21
//

#ifndef QT_LOG_TABLE_H
#define QT_LOG_TABLE_H

#include "model/db/Driver.h"
#include "model/db/Record.h"
#include "model/db/def.h"

namespace model::db {

class Record;

class Table {
public:

    explicit Table(model::db::Driver &driver);
    virtual ~Table() = default;

protected:
    model::db::Driver &dbDriver;
};


}

#endif //QT_LOG_TABLE_H
