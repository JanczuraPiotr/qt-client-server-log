//
// Created by piotr@janczura.pl on 2020.01.07
//

#ifndef CLIENT_INPUT_GETLOGSBETWEEN
#define CLIENT_INPUT_GETLOGSBETWEEN

#include <QDateTime>

#include "common/def.h"
#include "client/model/LogCollection.h"

namespace cl::input {


class GetLogsBetween {
public:
    GetLogsBetween(const cm::NetInput &input);
    virtual ~GetLogsBetween() = default;

    bool parse();

    QDateTime getBorderEarlier();
    QDateTime getBorderLatter();
    cl::model::LogCollection::ptr getLogCollection();

private: // const
    // getLogsBetween|yyyy-MM-dd-hh-mm-ss|yyyy-MM-dd-hh-mm-ss{...}"
    const cm::Index CORRECT_JSON_START = 54;
    const cm::Index CORRECT_DATA_START = 14;

private: // methods
    bool parseDateTime();
    bool parseJson();

private: // attributes
    cm::NetInput input;
    cm::Index lim;

    QDateTime borderEarlier;
    QDateTime borderLatter;

    cl::model::LogCollection::ptr logCollection;

public: // lock
    GetLogsBetween() = delete;
    GetLogsBetween(const GetLogsBetween &) = delete;
    GetLogsBetween(GetLogsBetween &&) = delete;
    GetLogsBetween &operator = (const GetLogsBetween&) = delete;
    GetLogsBetween &operator = (GetLogsBetween &&) = delete;

};

}


#endif
