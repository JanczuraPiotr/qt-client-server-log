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
#include "Log.h"

namespace model {


class LogTable {
public:
    typedef std::map<model::def::AutoId, model::Log::ptr> Map;

    LogTable();

    Map getAll();

private:
    model::db::Driver &dbDriver;
};

}



#endif //QT_LOG_LOGTABLE_H
