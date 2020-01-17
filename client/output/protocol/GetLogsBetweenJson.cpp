//
// Created by piotr@janczura.pl on 2020.01.08
//

#include "GetLogsBetweenJson.h"

namespace cl::output {

GetLogsBetweenJson::GetLogsBetweenJson(cm::NetProtocol netProtocol)
    : netProtocol(netProtocol)
{

}

cm::JsonString GetLogsBetweenJson::command(const cm::DateTime &earlier, const cm::DateTime &latter)
{
    cm::JsonString jsonString("getLogsBetween|" + earlier + "|" + latter);

    return jsonString;
}

}