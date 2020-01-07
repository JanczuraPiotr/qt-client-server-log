//
// Created by piotr@janczura.pl on 2019.12.15
//

#ifndef SERVER_INPUT_GETLOGSAFTER
#define SERVER_INPUT_GETLOGSAFTER

#include <string>
#include <QtCore/QString>
#include <QtCore/QDateTime>

#include "common/def.h"

namespace sv::input {

class GetLogsAfter {
public:
    GetLogsAfter(cm::NetInput input, cm::Index lim);
    virtual ~GetLogsAfter() = default;

    bool parse();

    QDateTime getBorderMoment();

private: // attributes
    QString input;
    cm::Index lim;

    QDateTime borderMoment;

public: // lock
    GetLogsAfter(const GetLogsAfter &) = delete;
    GetLogsAfter(GetLogsAfter &&) = delete;
    GetLogsAfter &operator = (const GetLogsAfter&) = delete;
    GetLogsAfter &operator = (GetLogsAfter &&) = delete;
    
};

}



#endif
