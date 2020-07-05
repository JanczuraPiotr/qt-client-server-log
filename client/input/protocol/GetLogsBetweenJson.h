//
// Created by piotr@janczura.pl on 2020.01.16
//

#ifndef CLIENT_INPUT_GETLOGSBETWEENJSON
#define CLIENT_INPUT_GETLOGSBETWEENJSON

#include "common/def.h"
#include "client/data/LogCollection.h"
#include "common/data/record/Log.hpp"

namespace cl::in {

namespace rec = cm::data::record;
namespace ent = cm::data::entity;

class GetLogsBetweenJson {
public:
    explicit GetLogsBetweenJson(cm::JsonString jsonString);
    virtual ~GetLogsBetweenJson() = default;

    bool parse();
    cl::data::LogCollection::ptr logCollection();

protected: // methods
    rec::Log::ptr parseLog(const cm::JsonString &jsonLog);

private: // attributes
    const cm::JsonString jsonString_;             ///< String który powinien zawierać kolekcję logów
    cl::data::LogCollection::ptr logCollection_; ///< Kolekcja logów na podstawie jsonString_;

public: // locks
    GetLogsBetweenJson(GetLogsBetweenJson&) = delete;
    GetLogsBetweenJson(GetLogsBetweenJson&&) = delete;
    GetLogsBetweenJson &operator = (GetLogsBetweenJson&) = delete;
    GetLogsBetweenJson &&operator = (GetLogsBetweenJson&&) = delete;

};

}


#endif
