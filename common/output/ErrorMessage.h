//
// Created by piotr@janczura.pl on 2019.11.26
//

#ifndef QT_CLIENT_SERVER_LOG_ERRORMESSAGE_H
#define QT_CLIENT_SERVER_LOG_ERRORMESSAGE_H

#include <QtCore/QString>

#include "common/def.h"

namespace cm::output {

class ErrorMessage {
public:
    static QString badCommand(const cm::NetCommand &command);
};

}



#endif //QT_CLIENT_SERVER_LOG_ERRORMESSAGE_H
