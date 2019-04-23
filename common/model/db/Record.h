//
// Created by piotr@janczura.pl on 2019.04.21
//

#ifndef QT_LOG_RECORD_H
#define QT_LOG_RECORD_H

#include <memory>
#include <map>
#include <QSqlRecord>
#include "model/db/def.h"
#include "model/db/Table.h"

namespace model::db {

class Table;

class Record {
    friend model::db::Table;

public:

    virtual ~Record() = default;

    QSqlRecord &generic();

private:
    explicit Record(QSqlRecord &rec);

    QSqlRecord &rec;
};

}



#endif //QT_LOG_RECORD_H
