//
// Created by piotr@janczura.pl on 2020.01.16
//

#include "GetLogsBetweenJson.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace sv::out {

QString GetLogsBetweenJson::one(
        const QString &command
        , const QDateTime &timeFrom
        , const QDateTime &timeTo
        , const r::Log::ptr &rLog)
{
    QJsonObject header;
    header["command"]   = command;
    header["timeFrom"]  = timeFrom.toString(cm::DATE_TIME_TEMPLATE.c_str());
    header["timeTo"]    = timeTo.toString(cm::DATE_TIME_TEMPLATE.c_str());

    QJsonObject record;
    record["id"]        = QString::number(rLog->id());
    record["timestamp"] = rLog->timestamp().toString(cm::DATE_TIME_TEMPLATE.c_str());
    record["priority"]  = QString::number(static_cast<int>(rLog->logPriority()));
    record["message"]   = rLog->message();

    QJsonArray data;
    data.append(record);

    QJsonObject root;
    root["header"]      = header;
    root["data"]        = data;

    QJsonDocument doc(root);
    return doc.toJson();
}

QString GetLogsBetweenJson::map(
        const QString &command
        , const QDateTime &timeFrom
        , const QDateTime &timeTo
        , const r::Log::map &records)
{

    QJsonObject header;
    header["command"]   = command;
    header["timeFrom"]  = timeFrom.toString(cm::DATE_TIME_TEMPLATE.c_str());
    header["timeTo"]    = timeTo.toString(cm::DATE_TIME_TEMPLATE.c_str());


    QJsonArray data;

    for (auto &it : records) {
        QJsonObject record;
        record["id"]        = QString::number(it.second->id());
        record["timestamp"] = it.second->timestamp().toString(cm::DATE_TIME_TEMPLATE.c_str());
        record["priority"]  = QString::number(static_cast<int>(it.second->logPriority()));
        record["message"]   = it.second->message();
        data.append(record);
    }

    QJsonObject root;
    root["header"]      = header;
    root["data"]        = data;

    QJsonDocument doc(root);
    return doc.toJson();
}

}