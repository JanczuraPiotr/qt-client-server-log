//
// Created by piotr@janczura.pl on 2019.04.18
//
#include "Log.h"

#include <QSqlQuery>
#include <QSqlRecord>

namespace model {

Log::Log(QSqlRecord &rec)
    : model::db::Record(rec)
{

}

QDateTime Log::getDateTime() {
    return rec.value(1).toDateTime();
}

common::LogPriority Log::getPriority() {
    return rec.value(2).toInt();
}

common::LogMsg Log::getText() {
    return rec.value(3).toString();
}


}