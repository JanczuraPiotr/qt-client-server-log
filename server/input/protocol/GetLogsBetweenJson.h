//
// Created by piotr@janczura.pl on 2019.12.15
//

#ifndef SERVER_INPUT_GETLOGSBETWEENJSON
#define SERVER_INPUT_GETLOGSBETWEENJSON

#include <QString>
#include <QDateTime>


#include "common/def.h"
#include "common/data/entity/Interval.hpp"

namespace sv::in {

class GetLogsBetweenJson {
public:
    explicit GetLogsBetweenJson(cm::NetInput in);
    virtual ~GetLogsBetweenJson() = default;
    bool parse();

    data::entity::Interval::ptr interval();

private: // methods
    cm::NetInput in_;
    data::entity::Interval::ptr interval_;

public: // lock
    GetLogsBetweenJson(const GetLogsBetweenJson &) = delete;
    GetLogsBetweenJson(GetLogsBetweenJson &&) = delete;
    GetLogsBetweenJson &operator = (const GetLogsBetweenJson&) = delete;
    GetLogsBetweenJson &operator = (GetLogsBetweenJson &&) = delete;
};

}


#endif
