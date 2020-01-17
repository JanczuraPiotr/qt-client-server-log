//
// Created by piotr@janczura.pl on 2020.01.16
//

#include "GetLogsBetween.h"

namespace cl::output {

GetLogsBetween::GetLogsBetween(cm::NetProtocol netProtocol)
        : netProtocol(netProtocol)
{

}

QString GetLogsBetween::command(const cm::DateTime &earlier, const cm::DateTime &latter)
{
    cm::JsonString jsonString("getLogsBetween|" + earlier + "|" + latter);

    return jsonString;
}

}