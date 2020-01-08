//
// Created by piotr@janczura.pl on 2019.12.15
//

#ifndef SERVER_INPUT_GETLOGSBETWEEN
#define SERVER_INPUT_GETLOGSBETWEEN

#include <QString>
#include <QDateTime>


#include "common/def.h"

namespace sv::input {

class GetLogsBetween {
public:
    explicit GetLogsBetween(cm::NetInput input, cm::Index lim);

    bool parse();

    QDateTime getBorderEarlier();
    QDateTime getBorderLatter();

private: // methods
    cm::NetInput input;
    cm::Index lim;

    QDateTime borderEarlier;
    QDateTime borderLatter;

public: // lock
    GetLogsBetween(const GetLogsBetween &) = delete;
    GetLogsBetween(GetLogsBetween &&) = delete;
    GetLogsBetween &operator = (const GetLogsBetween&) = delete;
    GetLogsBetween &operator = (GetLogsBetween &&) = delete;
};
}


#endif
