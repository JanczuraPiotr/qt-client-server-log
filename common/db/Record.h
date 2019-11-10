//
// Created by piotr@janczura.pl on 2019.07.23
//

#ifndef WRAPPER_RECORD_H
#define WRAPPER_RECORD_H

#include <memory>
#include <map>

#include <QSqlRecord>
#include <QSqlField>

#include "common/def.h"

namespace cm::db {

class Collection;

class Record {

friend Collection;
public:
    typedef std::shared_ptr<Record> ptr;
    virtual ~Record() = default;

    void id(AutoId id);
    AutoId id();
    virtual const QSqlRecord &genericRecord();

protected: // methods

    explicit Record(const QSqlRecord &rec);

protected: // attributes

    QSqlRecord rec;

private: // locks

    Record() = default;
    Record(const Record &other) = default;
    Record(Record &&other) = default;
    Record& operator = (const Record& other) = default;
    Record& operator = (Record&& other) = default;
};

}


#endif //WRAPPER_RECORD_H
