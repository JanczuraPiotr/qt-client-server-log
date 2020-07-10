//
// Created by piotr@janczura.pl on 2020.01.16
//

#ifndef SERVER_OUTPUT_LOGJSON
#define SERVER_OUTPUT_LOGJSON

#include <QDateTime>

#include "common/def.h"
#include "common/data/record/Log.hpp"

namespace d = data;
namespace e = d::entity;
namespace r = d::record;

namespace sv::out {

class GetLogsBetweenJson {
public:
    GetLogsBetweenJson() = default;
    virtual ~GetLogsBetweenJson() = default;

    QString map(r::Log::map records);
    QString one(
            cm::AutoId id
            , const QDateTime &dateTime
            , cm::LogPriority logPriority
            , const cm::Message &message);

public: // lock
    GetLogsBetweenJson(const GetLogsBetweenJson &) = delete;
    GetLogsBetweenJson(GetLogsBetweenJson &&) = delete;
    GetLogsBetweenJson &operator = (const GetLogsBetweenJson&) = delete;
    GetLogsBetweenJson &operator = (GetLogsBetweenJson &&) = delete;
};

}

#endif
