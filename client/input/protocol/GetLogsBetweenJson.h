//
// Created by piotr@janczura.pl on 2020.01.16
//

#ifndef CLIENT_INPUT_GETLOGSBETWEENJSON
#define CLIENT_INPUT_GETLOGSBETWEENJSON

#include "common/def.h"
#include "client/data/LogCollection.h"

namespace cl::in {

class GetLogsBetweenJson {
public:
    explicit GetLogsBetweenJson(cm::JsonString jsonString);
    GetLogsBetweenJson(GetLogsBetweenJson&) = delete;
    GetLogsBetweenJson(GetLogsBetweenJson&&) = delete;
    GetLogsBetweenJson &operator = (GetLogsBetweenJson&) = delete;
    GetLogsBetweenJson &&operator = (GetLogsBetweenJson&&) = delete;
    virtual ~GetLogsBetweenJson() = default;

    bool parse();

protected:
    bool parseLog(const cm::JsonString &jsonLog);

private:
    const cm::JsonString jsonString_;             ///< String który powinien zawierać kolekcję logów
    cl::data::LogCollection::ptr logCollection_; ///< Kolekcja logów na podstawie jsonString_;
};

}


#endif
