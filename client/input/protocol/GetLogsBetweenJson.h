//
// Created by piotr@janczura.pl on 2020.01.16
//

#ifndef CLIENT_INPUT_GETLOGSBETWEENJSON
#define CLIENT_INPUT_GETLOGSBETWEENJSON

#include "common/def.h"
#include "client/data/LogCollection.h"
#include "common/data/Data.hpp"
#include "common/data/record/Log.hpp"
#include "common/data/entity/Interval.hpp"

namespace cl::in {

namespace data = ::data;
namespace rec = data::record;
namespace ent = data::entity;

class GetLogsBetweenJson {
public:
    explicit GetLogsBetweenJson(cm::JsonString jsonString);
    virtual ~GetLogsBetweenJson() = default;

    ent::Interval::ptr interval();

    bool parse();
    rec::Log::map logMap();

protected: // methods
    rec::Log::ptr parseLog(const cm::JsonString &jsonLog);

private: // attributes
    const cm::JsonString jsonString_; ///< String który powinien zawierać kolekcję logów
    rec::Log::map logMap_;            ///< Kolekcja logów na podstawie jsonString_;
    ent::Interval::ptr interval_;

public: // locks
    GetLogsBetweenJson(GetLogsBetweenJson&) = delete;
    GetLogsBetweenJson(GetLogsBetweenJson&&) = delete;
    GetLogsBetweenJson &operator = (GetLogsBetweenJson&) = delete;
    GetLogsBetweenJson &&operator = (GetLogsBetweenJson&&) = delete;

};

}


#endif
