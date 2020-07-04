//
// Created by piotr@janczura.pl on 2020.01.08
//

#ifndef CLIENT_OUTPUT_GETLOGSBETWEEN
#define CLIENT_OUTPUT_GETLOGSBETWEEN

#include "common/def.h"

namespace cl::out {

class GetLogsBetweenJson {
public:
    explicit GetLogsBetweenJson();

    cm::JsonString command(const cm::DateTime &earlier, const cm::DateTime &latter);

private: // attributes

public: // lock
    GetLogsBetweenJson(const GetLogsBetweenJson &) = delete;
    GetLogsBetweenJson(GetLogsBetweenJson &&) = delete;
    GetLogsBetweenJson &operator = (const GetLogsBetweenJson&) = delete;
    GetLogsBetweenJson &operator = (GetLogsBetweenJson &&) = delete;
};

}


#endif
