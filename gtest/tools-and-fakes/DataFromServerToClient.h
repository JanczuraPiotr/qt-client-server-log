//
// Created by piotr@janczura.pl on 2020.01.08
//

#ifndef TEST_DATAFROMSERVERTOCLIENT_H
#define TEST_DATAFROMSERVERTOCLIENT_H

#include "common/def.h"

namespace test {

class DataFromServerToClient {
public:
    static cm::JsonString getLogsBetweenJson();
    static cm::JsonString getLogsBetweenEbnf();
};
}


#endif
