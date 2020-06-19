//
// Created by piotr@janczura.pl on 2020.06.19
//

#ifndef CLIENT_OUTPUT_OUTPUT
#define CLIENT_OUTPUT_OUTPUT

#include "../../common/def.h"

namespace cl::out {

/// \brief Klasa bazowa obsługi pakowanie danych wyjściowych.
/// Klasa pochodna na podstawie protokołu ładuje właściwą klasę z katalogu protokol która złoży bufor wyjściowy
class Output {
public:
    static void setProtocol(cm::NetProtocol netProtocol);

protected:
    static cm::NetProtocol netProtocol_;
};

}

#endif
