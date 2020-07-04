//
// Created by piotr@janczura.pl on 2020.01.16
//

#ifndef CLIENT_INPUT_LOGEBNF
#define CLIENT_INPUT_LOGEBNF

#include <QDateTime>

#include "common/def.h"
#include "server/data/LogRecord.h"

namespace cl::in {


class LogEBNF {
public:
    LogEBNF(cm::NetInput input, cm::Index lim);
    virtual ~LogEBNF() = default;

    bool parse();

    [[nodiscard]] QDateTime getTimestamp() const noexcept;
    [[nodiscard]] cm::AutoId getId() const noexcept;
    [[nodiscard]] cm::LogPriority getPriority() const noexcept;
    [[nodiscard]] cm::Message getMessage() const noexcept;

private: // attributes
    cm::NetInput input;
    cm::Index lim;

    QDateTime timestamp;
    cm::AutoId id;
    cm::LogPriority priority;
    cm::Message message;

public: // lock
    LogEBNF() = delete;
    LogEBNF(const LogEBNF &) = delete;
    LogEBNF(LogEBNF &&) = delete;
    LogEBNF &operator = (const LogEBNF&) = delete;
    LogEBNF &operator = (LogEBNF &&) = delete;

};

}

#endif
