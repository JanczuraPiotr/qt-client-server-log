//
// Created by piotr@janczura.pl on 2020.01.07
//

#ifndef CLIENT_INPUT_GETLOGSBEFORE
#define CLIENT_INPUT_GETLOGSBEFORE

#include "common/def.h"

namespace cl::input {


class GetLogsBefore {
public:
    GetLogsBefore(const cm::NetInput &input, cm::Index lim);
    virtual ~GetLogsBefore() = default;

    bool parse();

private: // attributes
    cm::NetInput input;
    cm::Index lim;

};

}

#endif
