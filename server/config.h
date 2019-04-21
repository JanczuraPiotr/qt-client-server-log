//
// Created by piotr@janczura.pl on 2019.04.18
//

#ifndef QT_LOG_CONFIG_H
#define QT_LOG_CONFIG_H

namespace sp9pj {

class Config {
public:
    static const QString dbHost()      { return "localhost";}
    static const QString dbName()      { return "qt-client-server-log";}
    static const QString dbUser()      { return "qt-client-server-log";}
    static const QString dbPassword()  { return "qt-client-server-log";}
};

}

#endif //QT_LOG_CONFIG_H
