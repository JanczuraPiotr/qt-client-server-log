//
// Created by piotr@janczura.pl on 2019.11.03
//

#include "ConfigFile.h"

#include <QDir>
#include <QDebug>

#include "common/exception/general.h"

namespace server {

ConfigFile::ConfigFile()
    : configDir("")
    , settings(nullptr)
    , dbHost("")
    , dbPort(0)
    , dbType("")
    , dbName("")
    , dbUser("")
    , dbPass("")
{

}

ConfigFile *ConfigFile::instance()
{
    static ConfigFile &&configFile = ConfigFile::instanceInit();
    return &configFile;
}

ConfigFile &&ConfigFile::instanceInit()
{
    static ConfigFile configFile;
    configFile.initFolderForConfigFile();
    configFile.readConfig();
    configFile.writeConfig();
    return std::move(configFile);
}

void ConfigFile::createConfigDir()
{
    QDir dir(getConfigDir());
    if (!dir.exists()) {
        if (!dir.mkdir(getConfigDir()) ){
            throw cm::ex::DirNoExist(getConfigDir());
        }
    }
}

QString ConfigFile::getConfigDir()
{
    return configDir;
}

QString ConfigFile::getDefaultConfigDir()
{
    return QDir::homePath() + "/.config/qt-log";
}

QString ConfigFile::getNameFileIni()
{
    return "qt-log.ini";
}

QString ConfigFile::getPathFileIni()
{
    return getConfigDir() + "/" + getNameFileIni();
}

void ConfigFile::initFolderForConfigFile()
{
    setConfigDir(getDefaultConfigDir());
    createConfigDir();
    setSettings(new QSettings(getPathFileIni(), QSettings::IniFormat));
}

void ConfigFile::setConfigDir(const QString &configDir)
{
    this->configDir = configDir;
}

void ConfigFile::setSettings(QSettings *settings)
{
    this->settings = settings;
}

QString ConfigFile::getDbHost()
{
    return dbHost;
}

cm::TCPPort ConfigFile::getDbPort()
{
    return dbPort;
}

QString ConfigFile::getDbType()
{
    return dbType;
}

QString ConfigFile::getDbName()
{
    if (getDbType() == "QSQLITE") {
        return getConfigDir() + "/" + dbName;
    } else {
        return dbName;
    }
}

QString ConfigFile::getDbUser(){
    return dbUser;
}

QString ConfigFile::getDbPass(){
    return dbPass;
}

void ConfigFile::readConfig()
{
    settings->beginGroup("database");
    dbHost = settings->value("dbHost","localhost").toString();
    dbPort = settings->value("dbPort", 0).toInt();
    dbType = settings->value("dbType","QSQLITE").toString();
    dbName = settings->value("dbName","qt-log.sqlite").toString();
    dbUser = settings->value("dbUser","admin").toString();
    dbPass = settings->value("dbPass","admin").toString();
    settings->endGroup();
}

void ConfigFile::writeConfig()
{
    settings->beginGroup("database");
    settings->setValue("dbHost", dbHost);
    settings->setValue("dbPort", dbPort);
    settings->setValue("dbType", dbType);
    settings->setValue("dbName", dbName);
    settings->setValue("dbUser", dbUser);
    settings->setValue("dbPass", dbPass);
    settings->endGroup();
}

}