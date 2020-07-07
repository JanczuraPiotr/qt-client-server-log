//
// Created by piotr@janczura.pl on 2020.01.16
//

#include "GetLogsBetweenJson.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "client/input/Log.h"
#include "common/algorithm/String.h"

namespace cl::in {

GetLogsBetweenJson::GetLogsBetweenJson(cm::JsonString jsonString)
    : jsonString_(std::move(jsonString))
    , interval_(ent::Interval::create())
{

}


ent::Interval::ptr GetLogsBetweenJson::interval()
{
    return interval_;
}

rec::Log::map GetLogsBetweenJson::logMap()
{
    return logMap_;
}

bool GetLogsBetweenJson::parse()
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString_.toUtf8());
    QJsonObject root = jsonDocument.object();

    for (auto &rootKey : root.keys()) {
        if (rootKey == "data") {
            QJsonArray data = root.value(rootKey).toArray();
            for (cm::Index i = 0; i < data.size(); ++i) {
                QJsonDocument tmpJson(data[i].toObject());
                QByteArray tmpArray = tmpJson.toJson();
                cm::JsonString tmpString(tmpArray);
                rec::Log::ptr recLog = parseLog(tmpString);
                if (recLog->isOk()) {
                    logMap_.insert(std::make_pair(recLog->id(), recLog));
                }
            }
        } else if (rootKey == "response") {
            QJsonObject response = root.value(rootKey).toObject();
            interval_->timeFrom(QDateTime::fromString(root["timeFrom"].toString(), cm::DATE_TIME_TEMPLATE.c_str()));
            interval_->timeTo(QDateTime::fromString(root["timeTo"].toString(), cm::DATE_TIME_TEMPLATE.c_str()));
        }
    }
    return true;
}

rec::Log::ptr GetLogsBetweenJson::parseLog(const cm::JsonString &jsonLog)
{
    ent::Log::ptr entLog = ent::Log::create();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonLog.toUtf8());

    QJsonObject root = jsonDocument.object();
    if ( ! root.empty()) {

        if (root["timestamp"].toString().size() == static_cast<cm::Index>(cm::DATE_TIME_TEMPLATE.size())) {
            if (root["timestamp"].isUndefined() || root["timestamp"].isNull()) {
                // @task wyjątek na brak log.timestamp
            } else {
                entLog->timestamp(root["timestamp"].toVariant().toDateTime());
            }
        }

        data::AutoId id = data::EMPTY_ID;
        if (root["id"].isUndefined() || root["id"].isNull()) {
            // @task wyjątek na brak log.id
        } else {
            id = static_cast<cm::AutoId>(root["id"].toVariant().toUInt());
        }

        if (root["priority"].isUndefined() || root["priority"].isNull()) {
            // @task wyjątek na brak log.message
        } else {
            entLog->logPriority(static_cast<cm::LogPriority>(root["priority"].toVariant().toInt()));
        }

        if (root["message"].isUndefined() || root["message"].isNull()) {
            // @task wyjątek na brak log.message
        } else {
            entLog->message(root["message"].toString());
        }

        return rec::Log::create(id, entLog);
    }
    return rec::Log::create(0, {});

}

}