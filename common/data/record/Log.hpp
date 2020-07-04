//
// Created by piotr@janczura.pl on 2020.07.04
//

#ifndef COMMON_RECORD_LOG
#define COMMON_RECORD_LOG

#include "common/data/Data.hpp"
#include "common/data/entity/Log.hpp"

namespace data::record {

class Log {
public:
    Log(AutoId id, const entity::Log &log);
    Log(AutoId id, QDateTime timestamp, cm::LogPriority logPriority, cm::Message message);
    virtual ~Log() = default;

    [[nodiscard]] AutoId id() const ;
    [[nodiscard]] QDateTime timestamp() const;
    [[nodiscard]] cm::LogPriority logPriority() const ;
    [[nodiscard]] cm::Message message() const ;

private:
    AutoId id_;
    entity::Log log_;
};

}

#endif
