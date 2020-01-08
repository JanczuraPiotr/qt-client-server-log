//
// Created by piotr@janczura.pl on 2020.01.08
//

#include "String.h"

#include <QDebug>

namespace cm::algorithm {

QString String::condense(const QString &string)
{
    QString str =string.simplified();
    return str.replace(" ", "");
}

}
