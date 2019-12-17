//
// Created by piotr@janczura.pl on 2019.04.18
//

#ifndef QT_LOG_COMMON_DEF_H
#define QT_LOG_COMMON_DEF_H

#include <map>
#include <QVariant>

namespace cm {

typedef unsigned AutoId;
typedef quint16 TCPPort;
typedef QString ColumnName;
typedef std::map<ColumnName, QVariant> Params;
typedef QString Message;
typedef QString JsonString;
typedef QString NetCommand;

enum class LogPriority {
    ok,
    info,
    warning,
    error
};

const int RECONNECT_TIME_IN_MILLISECONDS = 3000;
const int MAX_RECONNECT_ATTEMPTS = 3;

const std::string DATE_TIME_TEMPLATE = "yyyy-MM-dd hh:mm:ss";
}

#endif //QT_LOG_COMMON_DEF_H
