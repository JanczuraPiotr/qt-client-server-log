//
// Created by piotr@janczura.pl on 2020.01.08
//

#include "GetLogsBetweenJson.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace cl::out {

GetLogsBetweenJson::GetLogsBetweenJson()
{

}

cm::JsonString GetLogsBetweenJson::command(const cm::DateTime &earlier, const cm::DateTime &latter)
{
    QJsonObject obj;

    obj["command"]  = "getLogsBetween";
    obj["timeFrom"] = earlier;
    obj["timeTo"]   = latter;

    QJsonDocument doc(obj);
    return doc.toJson();
}

}