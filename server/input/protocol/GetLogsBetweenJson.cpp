//
// Created by piotr@janczura.pl on 2019.12.15
//

#include "GetLogsBetweenJson.h"

#include <QDebug>
#include <utility>

namespace sv::input {
//
//GetLogsBetweenJson::GetLogsBetweenJson(cm::NetInput input, cm::Index lim)
//    : input(std::move(input))
//    , lim(lim)
//    , borderEarlier()
//    , borderLatter()
//{
//
//}
//
//bool GetLogsBetweenJson::parse()
//{
//    // getLogsBetween|yyyy-MM-dd-hh-mm-ss|yyyy-MM-dd-hh-mm-ss"
//    const cm::Index CORRECT_INPUT_LONG = 54;
//    const cm::Index FIRST_LIM_INDEX = lim;
//    const cm::Index LAST_LIM_INDEX = lim + static_cast<cm::Index>(cm::DATE_TIME_IN_COMMAND_TEMPLATE.length()) + 1;
//
//    if (input.length() != CORRECT_INPUT_LONG) {
//        return false;
//    }
//    if (input.at(FIRST_LIM_INDEX) != '|' && input.at(LAST_LIM_INDEX) != '|') {
//        return false;
//    }
//
//    borderEarlier = QDateTime::fromString(
//            input.mid(FIRST_LIM_INDEX + 1, static_cast<cm::Index>(cm::DATE_TIME_IN_COMMAND_TEMPLATE.length()))
//            , cm::DATE_TIME_IN_COMMAND_TEMPLATE.c_str());
//    if (!borderEarlier.isValid()) {
//        return false;
//    }
//
//    borderLatter  = QDateTime::fromString(
//            input.mid(LAST_LIM_INDEX + 1, static_cast<cm::Index>(cm::DATE_TIME_IN_COMMAND_TEMPLATE.length()))
//            , cm::DATE_TIME_IN_COMMAND_TEMPLATE.c_str());
//    if (!borderLatter.isValid()) {
//        return false;
//    }
//
//    return true;
//}
//
//QDateTime GetLogsBetweenJson::getBorderEarlier()
//{
//    return borderEarlier;
//}
//
//QDateTime GetLogsBetweenJson::getBorderLatter()
//{
//    return borderLatter;
//}
//


}