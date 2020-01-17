//
// Created by piotr@janczura.pl on 2020.01.08
//

#ifndef CLIENT_OUTPUT_GETLOGSBETWEEN
#define CLIENT_OUTPUT_GETLOGSBETWEEN

#include "common/def.h"

namespace cl::output {

/*@work */ class GetLogsBetweenJson {
public:
    // @work uruchomić możliwość wyboru protokołu
    explicit GetLogsBetweenJson(cm::NetProtocol netProtocol);

    cm::JsonString command(const cm::DateTime &earlier, const cm::DateTime &latter);

private: // attributes
    cm::NetProtocol netProtocol;

public: // lock
    GetLogsBetweenJson(const GetLogsBetweenJson &) = delete;
    GetLogsBetweenJson(GetLogsBetweenJson &&) = delete;
    GetLogsBetweenJson &operator = (const GetLogsBetweenJson&) = delete;
    GetLogsBetweenJson &operator = (GetLogsBetweenJson &&) = delete;
};

}


#endif
