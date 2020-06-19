//
// Created by piotr@janczura.pl on 2020.06.19
//

#include "Input.hpp"



namespace cl::in {

cm::NetProtocol Input::netProtocol_ = cm::NetProtocol::DEFAULT;

void Input::setProtocol(cm::NetProtocol netProtocol) {
    Input::netProtocol_ = netProtocol;
}

}