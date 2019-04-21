//
// Created by piotr@janczura.pl on 2019.04.21
//

#include "Record.h"


namespace sp9pj::model::db {


Record::Record(const QSqlRecord &rec)
    : rec(rec)
{
}

}