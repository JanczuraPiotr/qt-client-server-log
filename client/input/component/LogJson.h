//
// Created by piotr@janczura.pl on 2020.01.16
//

#ifndef CLIENT_INPUT_LOGJSON_H
#define CLIENT_INPUT_LOGJSON_H

namespace cl::input {

class LogJson {
public:
    LogJson() = default;

public: // lock
    LogJson(const LogJson &) = delete;
    LogJson(LogJson &&) = delete;
    LogJson &operator = (const LogJson&) = delete;
    LogJson &operator = (LogJson &&) = delete;
};

}


#endif //QT_CLIENT_SERVER_LOG_LOGJSON_H
