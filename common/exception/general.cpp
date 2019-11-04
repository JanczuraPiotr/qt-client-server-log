//
// Created by piotr@janczura.pl on 2019.11.04
//

#include "general.h"

namespace ex {

General::General(const QString &msg)
    : exception()
    , msg_(msg)
{
}

QString General::type() const
{
    return "General exception";
}

QString General::msg() const
{
    return msg_;
}

DirNoExist::DirNoExist(const QString &type)
        : General(type)
{
}

QString DirNoExist::type() const
{
    return "Directory does not exist";
}

FileNoExist::FileNoExist(const QString &msg)
    : General(msg)
{
}

QString FileNoExist::type() const
{
    return "File does not exist";
}

}