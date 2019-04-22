//
// Created by piotr@janczura.pl on 2019.04.21
//

#include "Table.h"

namespace model::db {


Table::Table(model::db::Driver &dbDriver)
    : dbDriver(dbDriver)
{
}


}