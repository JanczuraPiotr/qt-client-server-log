//
// Created by piotr@janczura.pl on 2020.01.08
//

#include "GetLogsBetweenJson.h"

namespace cl::output {

GetLogsBetweenJson::GetLogsBetweenJson(const cm::DateTime &earlier, const cm::DateTime &latter)
    : earlier(earlier)
    , latter(latter)
{

}

cm::JsonString GetLogsBetweenJson::command()
{
    cm::JsonString jsonString("getLogsBetween|" + earlier + "|" + latter);

    return jsonString;
}

}