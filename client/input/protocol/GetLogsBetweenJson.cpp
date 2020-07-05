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
{

}

cl::data::LogCollection::ptr GetLogsBetweenJson::logCollection()
{
    return logCollection_;
}

bool GetLogsBetweenJson::parse()
{
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString_.toUtf8());
    QJsonObject root = jsonDocument.object();

    for (auto &rootKey : root.keys()) {
        QJsonArray data = root.value(rootKey).toArray();
        for (cm::Index i = 0; i < data.size(); ++i) {
            QJsonDocument tmpJson(data[i].toObject());
            QByteArray tmpArray = tmpJson.toJson();
            cm::JsonString tmpString(tmpArray);
            qDebug() << __FILE__ << __LINE__ << cm::alg::String::condense(tmpString);
            parseLog(tmpString);

//            cl::in::Log inputLog(); // @work uruchomić możliwość wyboru protokołu
//            if (!inputLog.parse(tmpString, 0)) {
//                return false;
//            }
//            logCollection_->insert(
//                    inputLog.getId()
//                    , inputLog.getTimestamp()
//                    , inputLog.getPriority()
//                    , inputLog.getMessage()
//            );
        }
    }

    return true;
}

rec::Log::ptr GetLogsBetweenJson::parseLog(const cm::JsonString &jsonLog)
{
    ent::Log::ptr entLog = ent::Log::create();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonLog.toUtf8());
    qDebug() << __FILE__ << __LINE__ << cm::alg::String::condense(jsonLog);

    QJsonObject root = jsonDocument.object();
    if ( ! root.empty()) {

        if (root["timestamp"].toString().size() == static_cast<cm::Index>(cm::DATE_TIME_TEMPLATE.size())) {
            if (root["timestamp"].isUndefined() || root["timestamp"].isNull()) {
                // @task wyjątek na brak log.timestamp
                result = false;
            }
            timestamp = root["timestamp"].toVariant().toDateTime();
            result = timestamp.isValid();
        } else {
            result = false;
        }

        if (root["id"].isUndefined() || root["id"].isNull()) {
            result = false;
            // @task wyjątek na brak log.id
        }
        id = static_cast<cm::AutoId>(root["id"].toVariant().toUInt());
        if (id < 1) {
            result = false;
        }

        if (root["priority"].isUndefined() || root["priority"].isNull()) {
            // @task wyjątek na brak log.message
            result = false;
        }
        priority = static_cast<cm::LogPriority>(root["priority"].toVariant().toInt());
        if (priority < cm::LogPriority::ok) {
            result = false;
        }

        if (root["message"].isUndefined() || root["message"].isNull()) {
            // @task wyjątek na brak log.message
            result = false;
        }
        message = root["message"].toString();


    } else {
        // @task wyjątek na brak danych w odebranym jsonie
        result = false;
    }
    return ;

}

}