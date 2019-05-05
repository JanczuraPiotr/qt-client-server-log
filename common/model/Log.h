//
// Created by piotr@janczura.pl on 2019.04.18
//

#ifndef QT_LOG_LOG_H
#define QT_LOG_LOG_H

#include <memory>

#include <QSqlQuery>
#include <QSqlRecord>
#include <common/def.h>

#include "common/model/db/def.h"
#include "common/model/db/Record.h"


namespace model {


class Log : public model::db::Record {
public:
    typedef std::shared_ptr<Log> ptr;
    typedef std::map<model::AutoId, ptr> map;

    Log(QSqlRecord &rec);
    Log(const QDateTime &dateTime, common::LogPriority logPriority, const common::LogMsg &logMsg);
    ~Log() override = default;

    void setDateTime(const QDateTime &dateTime);
    void setLogPriority(common::LogPriority logPriority);
    void setText(const common::LogMsg &logMsg);

    QDateTime getDateTime();
    common::LogPriority getPriority();
    common::LogMsg getText();

protected:
private:
    Log() = default;
};


}

#endif //QT_LOG_LOG_H
