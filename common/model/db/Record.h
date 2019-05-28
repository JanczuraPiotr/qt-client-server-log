//
// Created by piotr@janczura.pl on 2019.04.21
//

#ifndef QT_LOG_RECORD_H
#define QT_LOG_RECORD_H

#include <memory>
#include <map>

#include <QSqlRecord>

#include "common/model/db/def.h"
#include "common/model/db/Table.h" // ?

namespace model::db {

class Record {

public:
    typedef std::shared_ptr<Record> ptr;
    typedef std::map<model::AutoId, ptr> map;

    virtual ~Record() = default;
    QSqlRecord qSqlRecord();

protected:

    explicit Record(QSqlRecord &rec);
    Record();

    QSqlRecord rec;


};

}



#endif //QT_LOG_RECORD_H
