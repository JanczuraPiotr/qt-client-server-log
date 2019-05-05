//
// Created by piotr@janczura.pl on 2019.04.21
//

#ifndef QT_LOG_RECORD_H
#define QT_LOG_RECORD_H

#include <memory>
#include <map>

#include <QSqlRecord>

#include "common/model/db/def.h"
#include "common/model/db/Table.h"

namespace model::db {

class Record {

public:

    virtual ~Record() = default;
    QSqlRecord &generic();

protected:

    explicit Record(QSqlRecord &rec);
    Record();

    QSqlRecord rec; // @task > std::shared_ptr<QSglRecord>


};

}



#endif //QT_LOG_RECORD_H
