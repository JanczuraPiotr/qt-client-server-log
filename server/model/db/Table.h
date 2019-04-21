//
// Created by piotr@janczura.pl on 2019.04.21
//

#ifndef QT_LOG_TABLE_H
#define QT_LOG_TABLE_H

#include "Driver.h"

namespace sp9pj::model::db {


class Table {
public:
    explicit Table(sp9pj::model::db::Driver &driver);
    virtual ~Table() = default;
private:
    sp9pj::model::db::Driver &dbDriver;
};


}

#endif //QT_LOG_TABLE_H
