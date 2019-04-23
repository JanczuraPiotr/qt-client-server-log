//
// Created by piotr@janczura.pl on 2019.04.18
//

#ifndef QT_LOG_LOG_H
#define QT_LOG_LOG_H

#include <memory>
#include "common/model/db/def.h"
#include "model/db/Record.h"

namespace model {

class Log : public model::db::Record {
public:
    typedef std::shared_ptr<Log> ptr;
    typedef std::map<model::def::AutoId, ptr> map;

    ~Log() override = default;

};

}



#endif //QT_LOG_LOG_H
