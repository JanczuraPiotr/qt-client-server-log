//
// Created by piotr@janczura.pl on 2019.11.12
//

#ifndef QT_CLIENT_SERVER_LOG_EXCEPTION_H
#define QT_CLIENT_SERVER_LOG_EXCEPTION_H

#include "common/exception/general.h"

namespace cm::db::ex {

class General : public cm::ex::General{
public:
    explicit General(const QString &msg);
    ~General() override = default;
    [[nodiscard]] QString type() const override;
};

}



#endif //QT_CLIENT_SERVER_LOG_EXCEPTION_H
