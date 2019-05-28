//
// Created by piotr@janczura.pl on 2019.04.21
//

#include "Table.h"
#include <iostream>

namespace model::db {


Table::Table(model::db::Driver &dbDriver)
    : dbDriver(dbDriver)
{
}

model::AutoId Table::add(QSqlRecord record) {
    std::ignore = record;
    model::AutoId id = 0;
//    QSqlQuery query;
//    QSqlQueryModel *model= new QSqlQueryModel();

    std::cout << " add " << record.value(1).toDateTime().toString().toStdString() << std::endl;

    for (int i = 0; i < record.count(); ++i) {
        std::cout << record.fieldName(i).toStdString() << std::endl;
    }

    return id;
}

}