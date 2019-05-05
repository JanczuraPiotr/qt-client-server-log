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

Log::Log(const QDateTime &dateTime, common::LogPriority logPriority, const common::LogMsg &logMsg)
        : Record()
{
    setDateTime(dateTime);
    setLogPriority(logPriority);
    setText(logMsg);
}

void Log::setDateTime(const QDateTime &dateTime) {
    rec.setValue(1,dateTime);
}

void Log::setLogPriority(common::LogPriority logPriority) {
    rec.setValue(2, static_cast<int>(logPriority));
}

void Log::setText(const common::LogMsg &logMsg) {
    rec.setValue(3, logMsg);
}

QDateTime Log::getDateTime() {
    return rec.value(1).toDateTime();
}

common::LogPriority Log::getPriority() {
    return static_cast<common::LogPriority >(rec.value(2).toInt());
}

common::LogMsg Log::getText() {
    return rec.value(3).toString();
}


}