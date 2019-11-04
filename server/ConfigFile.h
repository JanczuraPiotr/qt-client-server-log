//
// Created by piotr@janczura.pl on 2019.04.18
//

#ifndef SERVER_CONFIG_H
#define SERVER_CONFIG_H

#include <QObject>
#include <QString>
#include <QSettings>
#include <common/def.h>

namespace server {

class ConfigFile : public QObject {
    Q_OBJECT
public:
    static ConfigFile *instance();
    virtual ~ConfigFile() = default;

    QString getDbHost();
    cm::TCPPort getDbPort();
    QString getDbType();
    QString getDbName();
    QString getDbUser();
    QString getDbPass();

private: // methods

    ConfigFile() = default;
    static ConfigFile && instanceInit();
    void createConfigDir();
    QString getDefaultConfigDir();
    QString getConfigDir();
    QString getNameFileIni();
    QString getPathFileIni();
    void initFolderForConfigFile();
    void setConfigDir(const QString &configDir);
    void setSettings(QSettings *settings);
    void readConfig();
    void writeConfig();

private: // attributes

    QString configDir;

private: // config

    QSettings *settings;

    QString dbHost;
    cm::TCPPort dbPort;
    QString dbType;
    QString dbName;
    QString dbUser;
    QString dbPass;
};
}


#endif //SERVER_CONFIG_H
