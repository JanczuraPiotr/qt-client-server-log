//
// Created by piotr@janczura.pl on 2019.12.15
//

#ifndef SERVER_INPUT_GETFIRSTLOG
#define SERVER_INPUT_GETFIRSTLOG

#include <QString>
#include <QDateTime>

#include "common/def.h"

namespace sv::input{


class GetLogsBefore {
public:
    explicit GetLogsBefore(cm::NetInput input, cm::Index lim);

    bool parse();
    QDateTime getBorderMoment();

private: // methods
    QString input;
    cm::Index lim;

    QDateTime borderMoment;

public: // lock
    GetLogsBefore(const GetLogsBefore &) = delete;
    GetLogsBefore(GetLogsBefore &&) = delete;
    GetLogsBefore &operator = (const GetLogsBefore&) = delete;
    GetLogsBefore &operator = (GetLogsBefore &&) = delete;
};

}


#endif
