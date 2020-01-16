//
// Created by piotr@janczura.pl on 2019.11.24
//

#ifndef CLIENT_INPUT_LOG
#define CLIENT_INPUT_LOG

#include <QDateTime>

#include "common/def.h"

namespace cl::input {
// @work na podstawie parametrów wiersza poleceń wybrać właściwy mechanizm
class Log {
public:
    // @task pozbądź się lim
    explicit Log(cm::NetInput input, cm::Index lim);
    virtual ~Log() = default;

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
    Log(const Log &) = delete;
    Log(Log &&) = delete;
    Log &operator = (const Log&) = delete;
    Log &operator = (Log &&) = delete;
};

}



#endif
