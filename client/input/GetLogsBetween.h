//
// Created by piotr@janczura.pl on 2020.01.07
//

#ifndef CLIENT_INPUT_GETLOGSBETWEEN
#define CLIENT_INPUT_GETLOGSBETWEEN

#include <QDateTime>

#include "common/def.h"
#include "client/model/LogCollection.h"

namespace cl::input {


class GetLogsBetween {
public:
    GetLogsBetween(const cm::NetInput &input, cm::Index lim);
    virtual ~GetLogsBetween() = default;

    bool parse();

    QDateTime getBorderEarlier();
    QDateTime getBorderLatter();
    cl::model::LogCollection::ptr getLogCollection();

private: // attributes
    cm::NetInput input;
    cm::Index lim;

    QDateTime borderEarlier;
    QDateTime borderLatter;

    cl::model::LogCollection::ptr logCollection;

};

}


#endif
