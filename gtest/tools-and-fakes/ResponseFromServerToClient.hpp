//
// Created by piotr@janczura.pl on 2020.01.08
//

#ifndef TEST_RESPONSE_FROMSERVER_TO_CLIENT
#define TEST_RESPONSE_FROMSERVER_TO_CLIENT

#include "../../server/data/LogRecord.h"
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


class ResponseFromServerToClient {
public:
    static cm::JsonString getLogBetweenJson();
    static cm::JsonString getLogsBetweenJson();

    static cm::JsonString getLogsBetweenEbnf();
    static data::LogRecord::ptr getLogRecord();
    static data::LogRecord::map getLogMap();
};
}


#endif
