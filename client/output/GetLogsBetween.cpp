//
// Created by piotr@janczura.pl on 2020.01.16
//

#include "GetLogsBetween.h"


namespace cl::out {

GetLogsBetween::GetLogsBetween(cm::NetProtocol netProtocol)
        : netProtocol(netProtocol)
{

}

QString GetLogsBetween::command(const cm::DateTime &earlier, const cm::DateTime &latter)
{
}

}