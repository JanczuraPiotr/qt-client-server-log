//
// Created by piotr@janczura.pl on 2020.07.04
//

#ifndef COMMON_ENTITY_LOG
#define COMMON_ENTITY_LOG

#include <QDateTime>

#include "common/def.h"
#include "common/data/Data.hpp"


namespace data::entity {

/// \brief Pojedyncza informacja
class Log {
public:
    typedef std::shared_ptr<Log> ptr;
    typedef std::multimap<QDateTime,Log> list;

    static ptr create();
    static ptr create(const QDateTime &timestamp, cm::LogPriority logPriority, const cm::Message &message);

    virtual ~Log() = default;

    bool isOk();

    void timestamp(const QDateTime &dateTime);
    void logPriority(cm::LogPriority logPriority);
    void message(const cm::Message &message);

    [[nodiscard]] QDateTime timestamp() const ;
    [[nodiscard]] cm::LogPriority logPriority() const ;
    [[nodiscard]] cm::Message message() const ;

protected:
    QDateTime timestamp_;
    cm::LogPriority logPriority_;
    cm::Message message_;

private: // locks
    Log() = default;
    Log(const QDateTime &timestamp, cm::LogPriority logPriority, const cm::Message &message);

    Log(const Log& other) = delete;
    Log(Log&&) = delete;
    Log &operator = (Log&) = delete;
    Log &&operator = (Log&&) = delete;

};

}


#endif
