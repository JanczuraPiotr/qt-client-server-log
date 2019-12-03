//
// Created by piotr@janczura.pl on 2019.11.26
//

#include "ErrorMessage.h"


namespace cm::output {

QString ErrorMessage::badCommand(const cm::NetCommand &command) {
    return "Odebrano nieobsługiwaną komendę : " + command;
}

}