//
// Created by piotr@janczura.pl on 2020.01.08
//

#include "String.h"

#include <QDebug>
#include <QDateTime>

namespace cm::alg {

QString String::condense(const QString &string)
{
    QString str =string.simplified();
    return str.replace(" ", "");
}

QString String::dateTimeInNetCommand(const cm::DateTime &dateTime) {
    QDateTime _dateTime = QDateTime::fromString(dateTime, cm::DATE_TIME_TEMPLATE.c_str());
    return _dateTime.toString(cm::DATE_TIME_IN_COMMAND_TEMPLATE.c_str());
}

QString String::dateTimeInNetCommand(const QDateTime &_dateTime) {
    return _dateTime.toString(cm::DATE_TIME_IN_COMMAND_TEMPLATE.c_str());
}

}
