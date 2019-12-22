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
    qDebug() << input.mid(lim + 1).toUtf8();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(input.mid(lim + 1).toUtf8());
    QJsonObject root = jsonDocument.object();

    if ( ! root.empty()) {

        if (root["timestamp"].isUndefined() || root["timestamp"].isNull()) {
            // @task wyjątek na brak log.borderMoment
            result = false;
        }
        timestamp.fromString(root["timestamp"].toString(), cm::DATE_TIME_TEMPLATE.c_str());

        if (root["logId"].isUndefined() || root["logId"].isNull()) {
            // @task wyjątek na brak log.logId
            result = false;
        }
        logId = static_cast<cm::AutoId >(root["logId"].toInt());

        if (root["logPriority"].isUndefined() || root["logPriority"].isNull()) {
            // @task wyjątek na brak log.message
            result = false;
        }
        logPriority = static_cast<cm::LogPriority>(root["logPriority"].toInt());

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