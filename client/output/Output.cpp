//
// Created by piotr@janczura.pl on 2020.06.19
//

#include "Output.hpp"


namespace cl::out {

cm::NetProtocol Output::netProtocol_ = cm::NetProtocol::DEFAULT;

void Output::setProtocol(cm::NetProtocol netProtocol) {
    Output::netProtocol_ = netProtocol;
}

}