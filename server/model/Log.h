//
// Created by piotr@janczura.pl on 2019.04.18
//

#ifndef QT_LOG_LOG_H
#define QT_LOG_LOG_H

#include <memory>
#include "server/model/def.h"

namespace sp9pj::model {

class Log {
public:
    typedef std::unique_ptr<Log> ptr;
    Log();


private:
    sp9pj::model::def::AutoId id;

};

}



#endif //QT_LOG_LOG_H
