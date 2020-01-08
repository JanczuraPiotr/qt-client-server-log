//
// Created by piotr@janczura.pl on 2020.01.08
//

#ifndef COMMON_ALGORITHM_STRING_H
#define COMMON_ALGORITHM_STRING_H

#include <QString>

namespace cm::algorithm {

class String {
public:
    static QString condense(const QString &string);

public: // lock
    String() = delete;
    String(const String &) = delete;
    String(String &&) = delete;
    String &operator = (const String&) = delete;
    String &operator = (String &&) = delete;
};

}


#endif
