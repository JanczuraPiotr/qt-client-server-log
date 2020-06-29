//
// Created by piotr@janczura.pl on 2020.01.08
//

#ifndef TEST_DATAFROMSERVERTOCLIENT_H
#define TEST_DATAFROMSERVERTOCLIENT_H

#include "../../server/model/LogRecord.h"
#include "common/def.h"

namespace test {

namespace data = sv::data;

// @work Zły projekt, klasa powinna dać się testować bez modyfikacji za pomocą dziedziczenia.
class LogRecord : public data::LogRecord {
public:
    static ptr makeShared(const QString &timestamp, cm::LogPriority priority, const cm::Message &message);

    ~LogRecord() override = default;

protected:
    LogRecord(const QDateTime &timestamp, cm::LogPriority priority, const cm::Message &message);
};

class DataFromServerToClient {
public:
    static cm::JsonString getLogsBetweenJson();
    static cm::JsonString getLogsBetweenEbnf();
    static data::LogRecord::ptr getLogRecord();
    static data::LogRecord::map getLogMap();
};
}


#endif
