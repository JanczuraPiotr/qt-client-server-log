//
// Created by piotr@janczura.pl on 2019.04.21
//

#ifndef QT_LOG_RECORD_H
#define QT_LOG_RECORD_H

#include <QSqlRecord>

namespace sp9pj::model::db {


class Record {
public:
    virtual ~Record() = default;
private:
    Record(const QSqlRecord &rec);
    QSqlRecord rec;
};

}



#endif //QT_LOG_RECORD_H
