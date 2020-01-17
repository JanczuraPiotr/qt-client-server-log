//
// Created by piotr@janczura.pl on 2020.01.07
//

#include "client/input/GetLogsBetween.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "common/algorithm/String.h"
#include "client/input/Log.h"

namespace cl::input {

GetLogsBetween::GetLogsBetween(cm::NetProtocol netProtocol)
        : netProtocol(netProtocol)
        , input()
        , lim(CORRECT_DATA_START)
        , borderEarlier()
        , borderLatter()
        , logCollection(cl::model::LogCollection::makeShared())
{
}

cl::model::LogCollection::ptr GetLogsBetween::getLogCollection() {
    return logCollection;
}

bool GetLogsBetween::parse(const cm::NetInput &input)
{
    this->input = input;
    if (this->input.indexOf('{') != CORRECT_JSON_START) {
        return false;
    }

    if (! parseDateTime()) {
        return false;
    }

    if (!parseJson()) {
        return false;
    }

    return true;
}

bool GetLogsBetween::parseDateTime()
{
    const cm::Index FIRST_LIM_INDEX = lim;
    const cm::Index LAST_LIM_INDEX = lim + static_cast<cm::Index>(cm::DATE_TIME_IN_COMMAND_TEMPLATE.length()) + 1;

    borderEarlier = QDateTime::fromString(
            input.mid(FIRST_LIM_INDEX + 1, static_cast<cm::Index>(cm::DATE_TIME_IN_COMMAND_TEMPLATE.length()))
            , cm::DATE_TIME_IN_COMMAND_TEMPLATE.c_str());
    if (!borderEarlier.isValid()) {
        return false;
    }

    borderLatter  = QDateTime::fromString(
            input.mid(LAST_LIM_INDEX + 1, static_cast<cm::Index>(cm::DATE_TIME_IN_COMMAND_TEMPLATE.length()))
            , cm::DATE_TIME_IN_COMMAND_TEMPLATE.c_str());
    if (!borderLatter.isValid()) {
        return false;
    }

    return true;
}

bool GetLogsBetween::parseJson()
{
    // @proposal Zamienić korzystanie z cl::input::Log do parsowania jsona z logami.
    // Utworzyć klasę parsującą jedną pozycję z logiem i wykorzystać ją ty i w klasie cl::input::Log.
    QJsonDocument jsonDocument = QJsonDocument::fromJson(input.mid(CORRECT_JSON_START).toUtf8());
    QJsonObject root = jsonDocument.object();

    for (auto &rootKey : root.keys()) {
        QJsonArray data = root.value(rootKey).toArray();
        for (cm::Index i = 0; i < data.size(); ++i) {
            QJsonDocument tmpJson(data[i].toObject());
            QByteArray tmpArray = tmpJson.toJson();
            cm::JsonString tmpString(tmpArray);
            cl::input::Log inputLog(cm::NetProtocol::JSON); // @work uruchomić możliwość wyboru protokołu
            if (!inputLog.parse(tmpString, 0)) {
                return false;
            }
            logCollection->insert(
                    inputLog.getId()
                    , inputLog.getTimestamp()
                    , inputLog.getPriority()
                    , inputLog.getMessage()
                    );
        }
    }

    return true;
}

QDateTime GetLogsBetween::getBorderEarlier()
{
    return borderEarlier;
}

QDateTime GetLogsBetween::getBorderLatter()
{
    return borderLatter;
}

}