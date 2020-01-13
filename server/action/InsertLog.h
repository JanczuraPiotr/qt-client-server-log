//
// Created by piotr@janczura.pl on 2019.11.12
//

#ifndef SERVER_ACTION_INSERTLOG
#define SERVER_ACTION_INSERTLOG


#include <QtCore/QDateTime>

#include "common/def.h"
#include "server/model/LogCollection.h"

namespace sv::action {

class InsertLog {
public:

    InsertLog();
    virtual ~InsertLog() = default;

    void timestamp(const QDateTime &dateTime);
    void logPriority(cm::LogPriority logPriority);
    void message(const cm::Message &message);

    void make();

    [[nodiscard]] QDateTime timestamp() const;
    [[nodiscard]] cm::LogPriority logPriority() const;
    [[nodiscard]] cm::Message message() const;
    [[nodiscard]] cm::AutoId id() const;

private: // methods

    QDateTime timestamp_;
    cm::LogPriority logPriority_;
    cm::Message message_;
    cm::AutoId id_;

    sv::model::LogCollection logCollection_;

public: // lock
    InsertLog(const InsertLog &) noexcept = delete;
    InsertLog(InsertLog &&) noexcept = delete;
    InsertLog &operator = (const InsertLog&) noexcept = delete;
    InsertLog &operator = (InsertLog &&) noexcept = delete;
};

}



#endif
