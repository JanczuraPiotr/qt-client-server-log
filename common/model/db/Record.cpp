//
// Created by piotr@janczura.pl on 2019.04.21
//

#include "Record.h"


namespace model::db {

Record::Record()
    : rec()
{
}

Record::Record(QSqlRecord &rec)
    : rec(rec)
{
}

QSqlRecord &Record::generic() {
    return rec;
}

}