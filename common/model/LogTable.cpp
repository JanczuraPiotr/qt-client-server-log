//
// Created by piotr@janczura.pl on 2019.04.18
//

#include "LogTable.h"

namespace model {


LogTable::LogTable(model::db::Driver &driver)
    : Table(driver)
{
}

//
//LogTable::Map LogTable::getAll() {
//    Map all;
//    QSqlQuery query;
//
//    qDebug() << query.exec("SELECT * FROM log");
//    QSqlRecord rec = query.record();
//
//    while (query.next()) {
//        qDebug() << "id "           << query.value(0);
//        qDebug() << "timestamp "    << query.value(1).toString();
//        qDebug() << "priority "     << query.value(2).toString();
//        qDebug() << "text "         << query.value(3).toString();
//    }
//
//    return all;
//}

}