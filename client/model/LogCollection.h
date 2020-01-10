//
// Created by piotr@janczura.pl on 2019.11.24
//

#ifndef CLIENT_MODEL_LOGCOLLECTION
#define CLIENT_MODEL_LOGCOLLECTION

#include <memory>

#include <QDateTime>

#include "common/def.h"
#include "client/model/LogRecord.h"

namespace cl::model {

class LogRecord;
class LogCollection {
public:
    typedef std::shared_ptr<LogCollection> ptr;
    static ptr makeShared();
    virtual ~LogCollection() = default;

    LogRecord::ptr getById(cm::AutoId id);
    LogRecord::ptr insert(
            cm::AutoId id
            , const QDateTime &timestamp
            , cm::LogPriority priority
            , const cm::Message &message);
    cm::Size size();

    LogRecord::map::iterator getBegin();
    LogRecord::map::iterator getEnd();

private: // attributes
    LogRecord::map records; // @proposal przełączyć na QCache

private: // lock
    explicit LogCollection();

public: // lock
    LogCollection(const LogCollection &) noexcept = delete;
    LogCollection(LogCollection &&) noexcept = delete;
    LogCollection &operator = (const LogCollection&) noexcept = delete;
    LogCollection &operator = (LogCollection &&) noexcept = delete;
    
};

}



#endif
