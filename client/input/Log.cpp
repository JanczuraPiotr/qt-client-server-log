//
// Created by piotr@janczura.pl on 2019.11.24
//

#include "Log.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QDebug>

namespace cl::input {


Log::Log(cm::NetInput input, cm::Index lim)
    : input(input)
    , lim(lim)
    , timestamp(QDateTime::fromString("1970-01-01 00:00:00", cm::DATE_TIME_TEMPLATE.c_str()))
    , logId(0)
    , logPriority(static_cast<cm::LogPriority>(0))
    , message("")
{
}

bool Log::parse()
{
    bool result = true;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(input.mid(lim).toUtf8());
    QJsonObject root = jsonDocument.object();

    if ( ! root.empty()) {

        if (root["timestamp"].toString().size() == static_cast<cm::Index>(cm::DATE_TIME_TEMPLATE.size())) {
            if (root["timestamp"].isUndefined() || root["timestamp"].isNull()) {
                // @task wyjątek na brak log.timestamp
                result = false;
            }
            timestamp = root["timestamp"].toVariant().toDateTime();
            result = timestamp.isValid();
        } else {
            result = false;
        }

        if (root["logId"].isUndefined() || root["logId"].isNull()) {
            result = false;
            // @task wyjątek na brak log.logId
        }
        logId = static_cast<cm::AutoId>(root["logId"].toVariant().toUInt());
        if (logId < 1) {
            result = false;
        }

        if (root["logPriority"].isUndefined() || root["logPriority"].isNull()) {
            // @task wyjątek na brak log.message
            result = false;
        }
        logPriority = static_cast<cm::LogPriority>(root["logPriority"].toVariant().toInt());
        if (logPriority < cm::LogPriority::ok) {
            result = false;
        }

        if (root["message"].isUndefined() || root["message"].isNull()) {
            // @task wyjątek na brak log.message
            result = false;
        }
        message = root["message"].toString();

    } else {
        // @task wyjątek na brak danych w odebranym jsonie
        result = false;
    }
    return result;
}

QDateTime Log::getTimestamp() const noexcept
{
    return timestamp;
}

cm::AutoId Log::getLogId() const noexcept
{
    return logId;
}

cm::LogPriority Log::getLogPriority() const noexcept
{
    return logPriority;
}

cm::Message Log::getMessage() const noexcept
{
    return message;
}




}