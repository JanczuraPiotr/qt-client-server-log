//
// Created by piotr@janczura.pl on 2020.07.10
//

#include "GetLogRecordJson.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace sv::in {

GetLogRecordJson::GetLogRecordJson(cm::NetInput in)
    : in_(std::move(in))
    , id_(d::EMPTY_ID)
{

}

bool GetLogRecordJson::parse()
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(in_.toUtf8());
    QJsonObject root = jsonDocument.object();

    if (root["command"].isNull() || root["command"].isUndefined()) {
        return false;
    }

    if(root["command"].toString() != "getLogById") {
        return false;
    }

    if (root["recId"].isNull() || root["recId"].isUndefined()) {
        return false;
    }

    id_ = root["recId"].toString().toUInt();

    return true;
}

d::AutoId GetLogRecordJson::id()
{
    return id_;
}

}