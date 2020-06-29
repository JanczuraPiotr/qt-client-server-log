//
// Created by piotr@janczura.pl on 2019.11.24
//

#include "Log.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QDebug>

namespace cl::in {


Log::Log(cm::NetProtocol netProtocol)
    : netProtocol(netProtocol)
    , timestamp(QDateTime::fromString("1970-01-01 00:00:00", cm::DATE_TIME_TEMPLATE.c_str()))
    , id(0)
    , priority(cm::LogPriority::none)
    , message("")
{
}

bool Log::parse(const cm::NetInput &input, const cm::Index &lim)
{
//    this->in = in;
//    this->lim = lim;
    bool result = true;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(input.mid(lim).toUtf8());
    QJsonObject root = jsonDocument.object();
    // @proposal : Ze względu na parsowanie pojedynczego logu przez tą klasę i GetLogsBetweenJson przenieść do osobnej klasy.
    // Uważam, że wzajemne wywoływanie klas tego samego poziomu jest błędem.
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

        if (root["id"].isUndefined() || root["id"].isNull()) {
            result = false;
            // @task wyjątek na brak log.id
        }
        id = static_cast<cm::AutoId>(root["id"].toVariant().toUInt());
        if (id < 1) {
            result = false;
        }

        if (root["priority"].isUndefined() || root["priority"].isNull()) {
            // @task wyjątek na brak log.message
            result = false;
        }
        priority = static_cast<cm::LogPriority>(root["priority"].toVariant().toInt());
        if (priority < cm::LogPriority::ok) {
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

cm::AutoId Log::getId() const noexcept
{
    return id;
}

cm::LogPriority Log::getPriority() const noexcept
{
    return priority;
}

cm::Message Log::getMessage() const noexcept
{
    return message;
}




}