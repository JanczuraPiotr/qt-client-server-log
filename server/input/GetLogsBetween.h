//
// Created by piotr@janczura.pl on 2019.12.15
//

#ifndef QT_CLIENT_SERVER_LOG_GETLOGSBETWEEN_H
#define QT_CLIENT_SERVER_LOG_GETLOGSBETWEEN_H

#include <QString>
#include <QDateTime>

namespace sv::input {

class GetLogsBetween {
public:
    explicit GetLogsBetween(const QString &input, int lim);

    bool parse();

    QDateTime getBorderEarlier();
    QDateTime getBorderLatter();

private: // methods
    QString input;
    int lim;

    QDateTime borderEarlier;
    QDateTime borderLatter;

public: // lock
    GetLogsBetween(const GetLogsBetween &) = delete;
    GetLogsBetween(GetLogsBetween &&) = delete;
    GetLogsBetween &operator = (const GetLogsBetween&) = delete;
    GetLogsBetween &operator = (GetLogsBetween &&) = delete;
};
}


#endif //QT_CLIENT_SERVER_LOG_GETLOGSBETWEEN_H
