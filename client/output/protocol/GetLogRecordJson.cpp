//
// Created by piotr@janczura.pl on 2020.07.09
//

#include "GetLogRecordJson.hpp"


#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

namespace cl::out {

GetLogRecordJson::GetLogRecordJson()
{

}

cm::JsonString GetLogRecordJson::command(cm::AutoId id)
{
    QJsonObject obj;

    obj["command"]  = "getLogById";
    obj["recId"]    = QString::number(id);

    QJsonDocument doc(obj);
    return doc.toJson();
}

}