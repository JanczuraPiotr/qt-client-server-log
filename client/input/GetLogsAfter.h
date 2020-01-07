//
// Created by piotr@janczura.pl on 2020.01.07
//

#ifndef CLIENT_INPUT_GETLOGSAFTER
#define CLIENT_INPUT_GETLOGSAFTER

#include "common/def.h"

namespace cl::input {


class GetLogsAfter {
public:
    GetLogsAfter(const cm::NetInput &input, cm::Index lim);
    virtual ~GetLogsAfter() = default;

    bool parse();

private: // attributes
    cm::NetInput input;
    cm::Index lim;

};

}

#endif
