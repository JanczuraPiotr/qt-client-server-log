//
// Created by piotr@janczura.pl on 2019.11.12
//

#include "exception.h"

namespace cm::db::ex {

General::General(const QString &msg)
    : cm::ex::General(msg)
{

}

QString General::type() const
{
    return "General database exception";
}

}