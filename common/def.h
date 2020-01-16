//
// Created by piotr@janczura.pl on 2019.04.18
//

#ifndef COMMON_DEF
#define COMMON_DEF

#include <map>
#include <QVariant>
#include <QList>
#include <QtGui/QStandardItem>

namespace cm {

typedef unsigned AutoId;
typedef QString Key;
typedef int Index; //std::size_t Index;
typedef std::size_t Size;
typedef quint16 TCPPort;
typedef QString ColumnName;
typedef std::map<ColumnName, QVariant> Params;
typedef QString Message;
typedef QString JsonString;
typedef QString EBNFString;
typedef QString NetCommand;
typedef QList<QStandardItem *> TextRow;
typedef QString DateTime; // Data i godzina w formie tekstowej według wzorca DATE_TIME_TEMPLATE

typedef QString NetInput;

enum class LogPriority {
    ok = 1, // @task usunąć LogPriority::ok
    info,
    warning,
    error
};

const Index IndexInfinity = std::numeric_limits<Index>::max();
const int RECONNECT_TIME_IN_MILLISECONDS = 3000;
const int MAX_RECONNECT_ATTEMPTS = 3;

const std::string DATE_TIME_TEMPLATE = "yyyy-MM-dd hh:mm:ss";
const std::string DATE_TIME_CONDENSED_TEMPLATE = "yyyyMMddhhmmss";
const std::string DATE_TIME_IN_COMMAND_TEMPLATE = "yyyy-MM-dd-hh-mm-ss";
}

#endif
