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


class LogTable : public model::db::Table{
public:

    explicit LogTable(db::Driver &driver);

    //db::Map getAll();

};

}



#endif //QT_LOG_LOGTABLE_H
