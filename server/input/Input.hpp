//
// Created by piotr@janczura.pl on 2020.06.19
//

#ifndef SERVER_INPUT_INPUT
#define SERVER_INPUT_INPUT

#include "../../common/def.h"

namespace sv::in {

/// \brief Klasa bazowa obsługi danych wejściowych serwera
/// Klasa pochodna na podstawie protokołu ładuje właściwą klasę z katalogu protokol która wykona parsowanie wejścia
class Input {
public:
    static void setProtocol(cm::NetProtocol netProtocol);

protected:
    static cm::NetProtocol netProtocol_;

};

}

#endif
