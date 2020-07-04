//
// Created by piotr@janczura.pl on 2019.11.24
//
#include "LogRecord.h"

#include <QDebug>
#include <QSqlField>

namespace cl::data{

LogRecord::ptr LogRecord::makeShared(
        cm::AutoId logId
        , const QDateTime &timestamp
        , cm::LogPriority logPriority
        , const cm::Message &message)
{
    return std::shared_ptr<LogRecord>(new LogRecord(logId, timestamp, logPriority, message));
}

QList<QStandardItem *> LogRecord::textRow() const noexcept
{
    // @task translacja kodu priorytetu na jego nazwę
    cm::TextRow row;
    row << new QStandardItem(QString::number(getLogId()));
    row << new QStandardItem(getTmestamp().toString(cm::DATE_TIME_TEMPLATE.c_str()));
    row << new QStandardItem(QString::number(static_cast<int>(getPriority())));
    row << new QStandardItem(getMessage());
    return row;
}

LogRecord::LogRecord(cm::AutoId logId, QDateTime timestamp, cm::LogPriority logPriority, cm::Message message)
    : logId(logId)
    , timestamp(std::move(timestamp))
    , logPriority(logPriority)
    , message(std::move(message))
{
}

cm::AutoId LogRecord::getLogId() const noexcept
{
    return logId;
}

QDateTime LogRecord::getTmestamp() const noexcept
{
    return timestamp;
}

cm::LogPriority LogRecord::getPriority() const noexcept
{
    return logPriority;
}

cm::Message LogRecord::getMessage() const noexcept
{
    return message;
}

}