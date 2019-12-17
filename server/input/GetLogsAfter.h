//
// Created by piotr@janczura.pl on 2019.12.15
//

#ifndef SERVER_INPUT_GETLASTGetLastLog_H
#define SERVER_INPUT_GETLASTGetLastLog_H

#include <string>
#include <QtCore/QString>
#include <QtCore/QDateTime>

namespace sv::input {

class GetLogsAfter {
public:
    explicit GetLogsAfter(const QString &input, int lim);

    bool parse();

    QDateTime getBorderMoment();

private: // methods
    QString input;
    int lim;

public: // lock
    GetLogsAfter(const GetLogsAfter &) = delete;
    GetLogsAfter(GetLogsAfter &&) = delete;
    GetLogsAfter &operator = (const GetLogsAfter&) = delete;
    GetLogsAfter &operator = (GetLogsAfter &&) = delete;
    
};

}



#endif //SERVER_INPUT_GETLASTGetLastLog_H
