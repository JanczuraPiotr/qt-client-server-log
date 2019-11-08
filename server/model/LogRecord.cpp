//
// Created by piotr@janczura.pl on 2019.04.18
//

#include "LogRecord.h"

namespace model {

LogRecord::ptr LogRecord::makeShared(const QSqlRecord &rec)
{
    return std::shared_ptr<LogRecord>(new LogRecord(rec));
}

LogRecord::LogRecord()
        : Record()
{
}

LogRecord::LogRecord(const QSqlRecord& record)
        : Record(record)
{

}


}