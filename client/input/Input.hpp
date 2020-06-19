//
// Created by piotr@janczura.pl on 2020.06.19
//

#ifndef CLIENT_INPUT_INPUT
#define CLIENT_INPUT_INPUT

#include "../../common/def.h"

namespace cl::in {

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
