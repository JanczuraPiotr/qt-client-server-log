//
// Created by piotr@janczura.pl on 2020.07.10
//

#include "GetLogRecordJson.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace sv::out {


cm::JsonString GetLogRecordJson::command(r::Log::ptr rLog)
{
    QJsonObject root;

    root["id"] = QString::number(rLog->id());
    root["timestamp"] = rLog->timestamp().toString(cm::DATE_TIME_TEMPLATE.c_str());
    root["priority"] = QString::number(static_cast<int>(rLog->logPriority()));
    root["message"] = rLog->message();

    QJsonDocument doc(root);
    return doc.toJson();
}

}