//
// Created by piotr@janczura.pl on 2019.04.18
//

#ifndef QT_LOG_COMMON_DEF_H
#define QT_LOG_COMMON_DEF_H

namespace common {

enum class LogPriority {
    ok,
    info,
    warning,
    error
};

typedef QString LogMsg;

}

#endif //QT_LOG_COMMON_DEF_H
