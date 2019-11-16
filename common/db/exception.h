//
// Created by piotr@janczura.pl on 2019.11.12
//

#ifndef COMMON_DB_EXCEPTION_H
#define COMMON_DB_EXCEPTION_H

#include "common/exception/general.h"

namespace cm::db::ex {

class General : public cm::ex::General{
public:
    explicit General(const QString &msg);
    ~General() override = default;
    [[nodiscard]] QString type() const override;
};

}



#endif //COMMON_DB_EXCEPTION_H
