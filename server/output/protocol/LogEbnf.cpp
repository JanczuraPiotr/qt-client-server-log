//
// Created by piotr@janczura.pl on 2020.01.16
//

#include "LogEbnf.h"

#include <boost/spirit/include/karma.hpp>

namespace karma = boost::spirit::karma;

namespace sv::out {


QString LogEBNF::one(
        cm::AutoId id
        , const QDateTime &dateTime
        , cm::LogPriority logPriority
        , const cm::Message &message)
{
    std::string out;
    karma::generate(
            std::back_inserter(out)

            ,karma::int_ << "|" << karma::string << "|" << karma::int_ << "|" << karma::string

            , id
            , dateTime.toString(cm::DATE_TIME_TEMPLATE.c_str()).toStdString()
            , static_cast<int>(logPriority)
            , message.toStdString()

    );
    return QString(out.c_str());
}

QString LogEBNF::map(model::LogRecord::map records)
{
    std::ignore = records;
//    for (auto &it : records) {
//        QJsonObject row;
//        row["id"]        = QString::number(it.second->id());
//        row["timestamp"] = it.second->timestamp().toString(cm::DATE_TIME_TEMPLATE.c_str());
//        row["priority"]  = QString::number(static_cast<int>(it.second->priority()));
//        row["message"]   = it.second->message();
//        jsonArray.append(row);
//    }


    return QString();
}

}