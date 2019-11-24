//
// Created by piotr@janczura.pl on 2019.11.24
//

#ifndef QT_CLIENT_SERVER_LOG_LOG_H
#define QT_CLIENT_SERVER_LOG_LOG_H

#include "common/def.h"

namespace cl::input {

class Log {
public:
    explicit Log() = default;
    virtual ~Log() = default;

    void parse(const cm::JsonString &log);

public: // lock
    Log(const Log &) = delete;
    Log(Log &&) = delete;
    Log &operator = (const Log&) = delete;
    Log &operator = (Log &&) = delete;
};

}



#endif //QT_CLIENT_SERVER_LOG_LOG_H
