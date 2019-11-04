//
// Created by piotr@janczura.pl on 2019.11.04
//

#include "SQLiteStructure.h"

#include <QSqlQuery>
#include <QSqlField>
#include <QVariant>

namespace cm::db {

bool SQLiteStructure::isLog()
{
    QSqlQuery query;
    query.exec("SELECT * FROM sqlite_master WHERE type ='table' AND name = 'log'");
    if (query.next()) {
        return true;
    } else {
        return false;
    }
}

void SQLiteStructure::initLog()
{
    QSqlQuery query;
    query.exec(
            "create table config ( "
            "  id           INTEGER   PRIMARY KEY AUTOINCREMENT, "
            "  timestamp    DATETIME  DEFAULT  CURRENT_TIMESTAMP,"
            "  priority     SMALLINT  DEFAULT  0,"
            "  text         TEXT      NOT NULL,"
            ")"
    );
}

cm::Params SQLiteStructure::logParams()
{
    cm::Params params = {
            {"timestamp",""},
            {"priority",""},
            {"text",""},
    };
    return params;
}

QSqlRecord SQLiteStructure::logRecord()
{
    QSqlRecord rec;
    rec.append(QSqlField("timestamp",  QVariant::DateTime));
    rec.append(QSqlField("priority",   QVariant::Int));
    rec.append(QSqlField("text",       QVariant::TextFormat));
    return rec;
}

}