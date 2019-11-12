//
// Created by piotr@janczura.pl on 2019.11.04
//

#ifndef EXCEPTION_GENERAL_H
#define EXCEPTION_GENERAL_H

#include <exception>
#include <QString>

namespace cm::ex {

class General : public std::exception {

public:

    explicit General(QString msg);
    ~General() override = default;
    [[nodiscard]] QString msg() const;
    [[nodiscard]] virtual QString type() const;

protected:
    const QString msg_;
};

class DirNoExist : public General {
public:
    explicit DirNoExist(const QString &msg);
    ~DirNoExist() override = default;
    [[nodiscard]] QString type() const override;
};

class FileNoExist : public General {
public:
    explicit FileNoExist(const QString &msg);
    ~FileNoExist() override = default;
    [[nodiscard]] QString type() const override ;
};

}


#endif //EXCEPTION_GENERAL_H
