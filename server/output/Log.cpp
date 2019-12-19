//
// Created by piotr@janczura.pl on 2019.11.19
//

#include "Log.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace sv::output {


cm::JsonString map(model::LogRecord::map)
{
    return cm::JsonString();
}


cm::JsonString Log::json(
        cm::AutoId id
        , const QDateTime &dateTime
        , cm::LogPriority logPriority
        , const cm::Message &message)
{
    QJsonObject root;
    root["logId"] = QString::number(id);
    root["borderMoment"] = dateTime.toString("yyyy-MM-dd hh:mm:ss");
    root["logPriority"] = QString::number(static_cast<int>(logPriority));
    root["message"] = message;
    QJsonDocument doc(root);
    return doc.toJson();
}

cm::JsonString Log::map(model::LogRecord::map records)
{
    return "[]";
}

}