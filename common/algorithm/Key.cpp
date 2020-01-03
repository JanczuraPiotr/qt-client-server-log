//
// Created by piotr@janczura.pl on 2020.01.03
//

#include "Key.h"

namespace cm::algorithm {

cm::Key Key::create(const QString &earlier, const QString &latter)
{
    // @task poprawić sposób generowania klucza dla okna z logami
    cm::Key key = (earlier.isEmpty() ? "-- " : earlier) + (latter.isEmpty() ? " --" : latter);
    return key;
}

}