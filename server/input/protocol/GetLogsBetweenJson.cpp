//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "GetLogsBetweenJson.h"

#include <utility>

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace sv::in {

GetLogsBetweenJson::GetLogsBetweenJson(cm::NetInput in)
    : in_(std::move(in))
    , interval_(data::entity::Interval::create())
{

}

data::entity::Interval::ptr GetLogsBetweenJson::interval()
{
    return interval_;
}

bool GetLogsBetweenJson::parse()
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(in_.toUtf8());
    QJsonObject root = jsonDocument.object();
    interval_->timeFrom(QDateTime::fromString(root["timeFrom"].toString(), cm::DATE_TIME_TEMPLATE.c_str()));
    interval_->timeTo(QDateTime::fromString(root["timeTo"].toString(), cm::DATE_TIME_TEMPLATE.c_str()));
    return true;
}


}