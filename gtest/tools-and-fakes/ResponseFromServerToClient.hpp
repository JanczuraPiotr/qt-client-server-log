//
// Created by piotr@janczura.pl on 2020.01.08
//

#ifndef TEST_RESPONSE_FROMSERVER_TO_CLIENT
#define TEST_RESPONSE_FROMSERVER_TO_CLIENT

#include "common/data/record/Log.hpp"
#include "common/def.h"

namespace d = data;
namespace e = d::entity;
namespace r = d::record;

namespace test {
//
//// @work Zły projekt, klasa powinna dać się testować bez modyfikacji za pomocą dziedziczenia.
//class LogRecord : public r::Log {
//public:
//    static ptr makeShared(const QString &timestamp, cm::LogPriority priority, const cm::Message &message);
//
//    ~LogRecord() override = default;
//
//protected:
//    LogRecord(const QDateTime &timestamp, cm::LogPriority priority, const cm::Message &message);
//};


class ResponseFromServerToClient {
public:
    static cm::JsonString getLogById();
    /// \brief W odpowiedzi na zapytanie server odsyła pustą listę
    static cm::JsonString getLogsBetweenJson_Empty();
    /// \brief W odpowiedzi na zapytanie server odsyła jeden rekord
    static cm::JsonString getLogsBetweenJson_One();
    /// \brief W odpowiedzi na zapytanie server odsyła wiele reklordów
    static cm::JsonString getLogsBetweenJson_Many();
    static r::Log::map getLogsBetweenMap_Many();

    static cm::JsonString getLogsBetweenEbnf();
    static r::Log::ptr getLogRecord();
    static r::Log::map getLogMap();
};
}


#endif
