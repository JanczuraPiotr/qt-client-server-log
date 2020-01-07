//
// Created by piotr@janczura.pl on 2020.01.07
//

#ifndef CLIENT_INPUT_GETLOGSBETWEEN
#define CLIENT_INPUT_GETLOGSBETWEEN

#include "common/def.h"

namespace cl::input {


class GetLogsBetween {
public:
    GetLogsBetween(const cm::NetInput &input, cm::Index lim);
    virtual ~GetLogsBetween() = default;

    bool parse();

private: // attributes
    cm::NetInput input;
    cm::Index lim;
};

}


#endif
