//
// Created by piotr@janczura.pl on 2019.04.21
//

#include "Table.h"

namespace model::db {


Table::Table(model::db::Driver &dbDriver)
    : dbDriver(dbDriver)
{
}

//model::AutoId Table::add(QSqlRecord &record) {
//    model::AutoId id = 0;
////    QSqlQuery query;
////    QSqlQueryModel *model= new QSqlQueryModel();
////
////    log->generic();
//    return id;
//}

}