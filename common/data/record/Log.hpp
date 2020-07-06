//
// Created by piotr@janczura.pl on 2020.07.04
//

#ifndef COMMON_RECORD_LOG
#define COMMON_RECORD_LOG

#include <memory>

#include "common/data/Data.hpp"
#include "common/data/entity/Log.hpp"

namespace data::record {

class Log {
public:
//    friend std::make_shared<Log>(AutoId id, const entity::Log &log);
//    friend std::make_shared<Log>(AutoId id, QDateTime timestamp, cm::LogPriority logPriority, cm::Message message);

    typedef std::shared_ptr<Log> ptr;
    typedef std::map<AutoId, ptr> map;
    static ptr create(AutoId id, entity::Log::ptr log);
    static ptr create(AutoId id, const QDateTime &timestamp, cm::LogPriority logPriority, const cm::Message &message);

    virtual ~Log() = default;

    bool isOk();
    [[nodiscard]] AutoId id() const ;
    [[nodiscard]] QDateTime timestamp() const;
    [[nodiscard]] cm::LogPriority logPriority() const ;
    [[nodiscard]] cm::Message message() const ;

private: // methods
    Log(AutoId id, entity::Log::ptr &log);
    Log(AutoId id, const QDateTime &timestamp, cm::LogPriority logPriority, const cm::Message &message);

private: // attributes
    AutoId id_;
    entity::Log::ptr log_;

public: // locks
    Log(Log&) = delete;
    Log(Log&&) = delete;
    Log &operator = (Log&) = delete;
    Log &&operator = (Log&&) = delete;
};

}

#endif
