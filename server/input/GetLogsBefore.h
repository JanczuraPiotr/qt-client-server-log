//
// Created by piotr@janczura.pl on 2019.12.15
//

#ifndef SERVER_INPUT_GETFIRSTLOG_H
#define SERVER_INPUT_GETFIRSTLOG_H

#include <QString>
#include <QDateTime>

namespace sv::input{


class GetLogsBefore {
public:
    explicit GetLogsBefore(const QString &input, int lim);

    bool parse();
    QDateTime getBorderMoment();

private: // methods
    QString input;
    int lim;

    QDateTime borderMoment;

public: // lock
    GetLogsBefore(const GetLogsBefore &) = delete;
    GetLogsBefore(GetLogsBefore &&) = delete;
    GetLogsBefore &operator = (const GetLogsBefore&) = delete;
    GetLogsBefore &operator = (GetLogsBefore &&) = delete;
};

}


#endif //SERVER_INPUT_GETFIRSTLOG_H
