//
// Created by piotr@janczura.pl on 2019.04.18
//

#ifndef QT_LOG_LOGTABLE_H
#define QT_LOG_LOGTABLE_H

#include <map>

#include <QtSql>
#include <QSqlDatabase>

#include "common/def.h"
#include "server/model/db/Driver.h"
#include "server/model/Log.h"

namespace sp9pj::model {


class LogTable {
public:
    typedef std::map<sp9pj::conf::AutoId, sp9pj::model::Log::ptr> Map;

    LogTable();

    Map getAll();

private:
    sp9pj::model::db::Driver &dbDriver;
};

}



#endif //QT_LOG_LOGTABLE_H
