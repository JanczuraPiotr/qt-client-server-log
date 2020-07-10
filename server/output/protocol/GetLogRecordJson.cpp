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
    QJsonObject header;
    header["command"] = "getLogById";
    header["logId"]   = "1";

    QJsonObject data;
    data["id"] = QString::number(rLog->id());
    data["timestamp"] = rLog->timestamp().toString(cm::DATE_TIME_TEMPLATE.c_str());
    data["priority"] = QString::number(static_cast<int>(rLog->logPriority()));
    data["message"] = rLog->message();

    QJsonObject root;
    root["header"]      = header;
    root["data"]        = data;

    QJsonDocument doc(root);
    return doc.toJson();
}

}