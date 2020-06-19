//
// Created by piotr@janczura.pl on 2020.01.16
//

#include "LogJson.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace sv::out {

//QString LogJson::one(
//        cm::AutoId id
//        , const QDateTime &dateTime
//        , cm::LogPriority logPriority
//        , const cm::Message &message)
//{
//    QJsonObject root;
//    root["id"] = QString::number(id);
//    root["timestamp"] = dateTime.toString(cm::DATE_TIME_TEMPLATE.c_str());
//    root["priority"] = QString::number(static_cast<int>(logPriority));
//    root["message"] = message;
//    QJsonDocument doc(root);
//    return doc.toJson();
//}
//
//QString LogJson::map(model::LogRecord::map records)
//{
//    QJsonArray jsonArray;
//
//    for (auto &it : records) {
//        QJsonObject row;
//        row["id"]        = QString::number(it.second->id());
//        row["timestamp"] = it.second->timestamp().toString(cm::DATE_TIME_TEMPLATE.c_str());
//        row["priority"]  = QString::number(static_cast<int>(it.second->priority()));
//        row["message"]   = it.second->message();
//        jsonArray.append(row);
//    }
//
//    QJsonDocument doc(jsonArray);
//    return doc.toJson();
//}

}