//
// Created by piotr@janczura.pl on 2019.04.18
//

#ifndef QT_LOG_LOGTABLE_H
#define QT_LOG_LOGTABLE_H

#include <map>

#include <QtSql>
#include <QSqlDatabase>

#include "common/def.h"
#include "common/model/db/Driver.h"
#include "common/model/db/Table.h"
#include "common/model/Log.h"

namespace model {


class LogTable : public model::db::Table {
public:

    explicit LogTable(model::db::Driver &driver);
    model::AutoId add(model::Log::ptr log);
    static model::Log::map getAll();

};

}



#endif //QT_LOG_LOGTABLE_H
