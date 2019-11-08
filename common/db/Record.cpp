//
// Created by piotr@janczura.pl on 2019.07.23
//

#include "Record.h"

namespace cm::db {

Record::Record()
    : rec()
{
}

Record::Record(const QSqlRecord &rec)
    : rec(rec)
{
}

void Record::id(AutoId id)
{
    if (rec.contains("id")) {
        rec.value("id").setValue(id);
    } else {
        QSqlField field;
        field.setName("id");
        field.setValue(id);
        rec.append(field);
    }
}

AutoId Record::id()
{
    if (rec.contains("id")) {
        return rec.value("id").toUInt();
    } else {
        return 0;
    }
}

const QSqlRecord &Record::genericRecord() {
    return rec;
}

}
