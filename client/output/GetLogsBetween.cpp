//
// Created by piotr@janczura.pl on 2020.01.08
//

#include "GetLogsBetween.h"

namespace cl::output {

GetLogsBetween::GetLogsBetween(const cm::DateTime &earlier, const cm::DateTime &latter)
    : earlier(earlier)
    , latter(latter)
{

}

cm::JsonString GetLogsBetween::command()
{
    cm::JsonString jsonString("getLogsBetween|" + earlier + "|" + latter);

    return jsonString;
}

}