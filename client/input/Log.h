//
// Created by piotr@janczura.pl on 2019.11.24
//

#ifndef CLIENT_INPUT_LOG
#define CLIENT_INPUT_LOG

#include <QDateTime>

#include "common/def.h"

namespace cl::input {
// @work na podstawie parametrów wiersza poleceń wybrać właściwy protokół
// @work uruchomić możliwość wyboru protokołu
class Log {
public:
    // @task pozbądź się lim
    explicit Log(cm::NetProtocol netProtocol);// @work uruchomić możliwość wyboru protokołu
    virtual ~Log() = default;

    bool parse(const cm::NetInput &input, const cm::Index &lim);

    [[nodiscard]] QDateTime getTimestamp() const noexcept;
    [[nodiscard]] cm::AutoId getId() const noexcept;
    [[nodiscard]] cm::LogPriority getPriority() const noexcept;
    [[nodiscard]] cm::Message getMessage() const noexcept;

private: // attributes
    cm::NetProtocol netProtocol;

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
