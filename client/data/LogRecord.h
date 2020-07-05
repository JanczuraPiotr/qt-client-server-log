//
// Created by piotr@janczura.pl on 2019.11.24
//

#ifndef CLIENT_MODEL_LOGRECORD
#define CLIENT_MODEL_LOGRECORD

#include <memory>

#include <QtCore/QDateTime>
#include <QSqlRecord>
#include <QStandardItem>

#include "common/def.h"

namespace cl::data {

// @work przenieść do common i ujednolicić z sv::data::LogRecord
class LogRecord {
    friend class LogCollection;
public:
    typedef std::shared_ptr<LogRecord> ptr;
    typedef std::map<cm::AutoId, ptr> map;

    virtual ~LogRecord() = default;

    [[nodiscard]] cm::TextRow textRow() const noexcept;
    [[nodiscard]] cm::AutoId getLogId() const noexcept;
    [[nodiscard]] QDateTime getTmestamp() const noexcept;
    [[nodiscard]] cm::LogPriority getPriority() const noexcept;
    [[nodiscard]] cm::Message getMessage() const noexcept;

protected: // methods
    static ptr makeShared(
            cm::AutoId logId
            , const QDateTime &timestamp
            , cm::LogPriority logPriority
            , const cm::Message &message);
    explicit LogRecord(
            cm::AutoId logId
            , QDateTime timestamp
            , cm::LogPriority lopPriority
            , cm::Message message);

private: // attributes
    cm::AutoId logId;
    QDateTime timestamp;
    cm::LogPriority logPriority;
    cm::Message message;

public: // lock
    LogRecord(const LogRecord &) = delete;
    LogRecord(LogRecord &&) = delete;
    LogRecord &operator = (const LogRecord&) = delete;
    LogRecord &operator = (LogRecord &&) = delete;
};

}



#endif
