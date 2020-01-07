//
// Created by piotr@janczura.pl on 2019.11.24
//

#ifndef CLIENT_INPUT_LOG_H
#define CLIENT_INPUT_LOG_H

#include <QDateTime>

#include "common/def.h"

namespace cl::input {

class Log {
public:
    explicit Log(cm::NetInput input, cm::Index lim);
    virtual ~Log() = default;

    bool parse();

    [[nodiscard]] QDateTime getTimestamp() const noexcept;
    [[nodiscard]] cm::AutoId getLogId() const noexcept;
    [[nodiscard]] cm::LogPriority getLogPriority() const noexcept;
    [[nodiscard]] cm::Message getMessage() const noexcept;

private: // attributes
    cm::NetInput input;
    cm::Index lim;

    QDateTime timestamp;
    cm::AutoId logId;
    cm::LogPriority logPriority;
    cm::Message message;

public: // lock
    Log(const Log &) = delete;
    Log(Log &&) = delete;
    Log &operator = (const Log&) = delete;
    Log &operator = (Log &&) = delete;
};

}



#endif //QT_CLIENT_SERVER_LOG_LOG_H
