//
// Created by piotr@janczura.pl on 2019.04.18
//

#ifndef QT_LOG_COMMON_DEF_H
#define QT_LOG_COMMON_DEF_H

#include <map>
#include <QVariant>

namespace cm {

typedef unsigned AutoId;
typedef int TCPPort;
typedef QString ColumnName;
typedef std::map<ColumnName, QVariant> Params;
typedef QString Message;

enum class LogPriority {
    ok,
    info,
    warning,
    error
};


}

#endif //QT_LOG_COMMON_DEF_H
