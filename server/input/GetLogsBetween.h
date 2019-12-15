//
// Created by piotr@janczura.pl on 2019.12.15
//

#ifndef QT_CLIENT_SERVER_LOG_GETLOGSBETWEEN_H
#define QT_CLIENT_SERVER_LOG_GETLOGSBETWEEN_H

#include <string>

namespace sv::input {

class GetLogsBetween {
public:
    explicit GetLogsBetween(const std::string &input);

    bool parse();

private: // methods
    std::string input;

public: // lock
    GetLogsBetween(const GetLogsBetween &) = delete;
    GetLogsBetween(GetLogsBetween &&) = delete;
    GetLogsBetween &operator = (const GetLogsBetween&) = delete;
    GetLogsBetween &operator = (GetLogsBetween &&) = delete;
};
}


#endif //QT_CLIENT_SERVER_LOG_GETLOGSBETWEEN_H
