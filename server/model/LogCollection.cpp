//
// Created by piotr@janczura.pl on 2019.04.18
//
#include <iostream>
#include <common/exception/general.h>
#include "LogCollection.h"

namespace model {

LogCollection::LogCollection() noexcept
    : Collection()
    , map()
{

}

QSqlRecord LogCollection::genericRecord() noexcept
{
    QSqlRecord rec;
    rec.append(QSqlField("timestamp",  QVariant::DateTime));
    rec.append(QSqlField("priority",   QVariant::Int));
    rec.append(QSqlField("text",       QVariant::TextFormat));
    return rec;
}

LogRecord::ptr LogCollection::get() noexcept
{
    genericRecord();
    return model::LogRecord::makeShared(genericRecord());
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