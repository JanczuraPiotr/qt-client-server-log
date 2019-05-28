//
// Created by piotr@janczura.pl on 2019.04.18
//

#include "LogTable.h"

#include <memory>
#include <map>

namespace model {


LogTable::LogTable(model::db::Driver &driver)
    : Table(driver)
{
}

model::AutoId LogTable::add(model::Log::ptr log) {
    return Table::add(log->qSqlRecord());
}

model::Log::map LogTable::getAll() {
    model::Log::map all;

    QSqlQuery query;
    query.exec("SELECT * FROM log");

    while (query.next()) {
        auto rec = query.record();
        all.insert(
                std::make_pair(
                        query.value(0).toUInt()
                        , std::make_shared<model::Log>(rec)));
    }

    return all;
}

}