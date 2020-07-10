//
// Created by piotr@janczura.pl on 2019.11.19
//

#ifndef SERVER_OUTPUT_LOG
#define SERVER_OUTPUT_LOG

#include <QDateTime>

#include "common/def.h"
#include "server/model/LogRecord.h"

namespace sv::out {
// @work na podstawie parametrów wiersza poleceń wybrać właściwy mechanizm
class GetLogsBetween {
public:
    explicit GetLogsBetween(cm::NetProtocol netProtocol);// @work uruchomić możliwość wyboru protokołu
    virtual ~GetLogsBetween() = default;

    QString map(data::LogRecord::map records);
    QString one(
            cm::AutoId id
            , const QDateTime &dateTime
            , cm::LogPriority logPriority
            , const cm::Message &message);

private: //attributes
    cm::NetProtocol netProtocol;

public: // lock
    GetLogsBetween(const GetLogsBetween &) = delete;
    GetLogsBetween(GetLogsBetween &&) = delete;
    GetLogsBetween &operator = (const GetLogsBetween&) = delete;
    GetLogsBetween &operator = (GetLogsBetween &&) = delete;
};


}


#endif