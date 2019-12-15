//
// Created by piotr@janczura.pl on 2019.11.24
//

#include "Log.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

namespace cl::input {


Log::Log()
    : timestamp(QDateTime::fromString("1970-01-01 00:00:00", "yyyy-MM-dd HH:mm:ss"))
    , logId(0)
    , logPriority(static_cast<cm::LogPriority>(0))
    , message("")
{
}

void Log::parse(const cm::JsonString &log)
{
    std::ignore = log;

    QJsonDocument jsonDocument = QJsonDocument::fromJson(log.toUtf8());
    QJsonObject root = jsonDocument.object();

    if ( ! root.empty()) {

        if (root["dateTime"].isUndefined() || root["dateTime"].isNull()) {
            // @task wyjątek na brak log.dateTime
        }
        timestamp.fromString(root["dateTime"].toString(), "yyyy-MM-dd HH:mm:ss");

        if (root["logId"].isUndefined() || root["logId"].isNull()) {
            // @task wyjątek na brak log.logId
        }
        logId = static_cast<cm::AutoId >(root["logId"].toInt());

        if (root["logPriority"].isUndefined() || root["logPriority"].isNull()) {
            // @task wyjątek na brak log.message
        }
        logPriority = static_cast<cm::LogPriority>(root["logPriority"].toInt());

        if (root["message"].isUndefined() || root["message"].isNull()) {
            // @task wyjątek na brak log.message
        }
        message = root["message"].toString();

    } else {
        // @task wyjątek na brak danych w odebranym jsonie
    }
}

QDateTime Log::getTimestamp()
{
    return timestamp;
}

cm::AutoId Log::getLogId()
{
    return logId;
}

cm::LogPriority Log::getLogPriority()
{
    return logPriority;
}

cm::Message Log::getMessage()
{
    return message;
}




}