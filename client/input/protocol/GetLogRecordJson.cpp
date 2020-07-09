//
// Created by piotr@janczura.pl on 2020.01.16
//

#include "GetLogRecordJson.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace cl::in {

GetLogRecordJson::GetLogRecordJson(cm::NetInput &&input)
    : input_(input)
{

}


bool GetLogRecordJson::parse()
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(input_.toUtf8());
    QJsonObject root = jsonDocument.object();

    if (root["header"].isNull() || root["header"].isUndefined()) {
        return false;
    }
    if(root["data"].isNull() || root["data"].isUndefined()) {
        return false;
    }

    QJsonObject header = root["header"].toObject();
    auto cmd = header["cmd"];
    cm::AutoId id = header["logId"].toString().toUInt();

    ent::Log::ptr logEnt = ent::Log::create();

    QJsonObject data = root["data"].toObject();

//    if(data["id"].isUndefined() || data["id"].isUndefined()) {
//    } else {
//        if (id != data["id"].toString().toUInt()) {
//
//        }
//    }

    if(data["message"].isUndefined() || data["message"].isNull()) {
        return false;
    } else {
        logEnt->message(data["message"].toString());
    }

    if(data["priority"].isUndefined() || data["priority"].isNull()) {
        return false;
    } else {
        logEnt->logPriority(data["priority"].toString().toUShort());
    }

    if(data["timestamp"].isUndefined() || data["timestamp"].isNull()) {
        return false;
    } else {
        logEnt->timestamp(data["timestamp"].toVariant().toDateTime());
    }

    logRec_ = rec::Log::create(id, logEnt);

    return true;
}

rec::Log::ptr GetLogRecordJson::record()
{
    return logRec_;
}

}