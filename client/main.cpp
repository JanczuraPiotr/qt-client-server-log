//
// Created by piotr@janczura.pl on 2019.04.13
//

#include <QApplication>
#include <iostream>
#include <QDebug>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    qDebug() << "client ";
    std::cout << "client" << std::endl;
    return 0;
}

// @task main window
// @task table add
// @task table update
// @task table delete
// @task table search
// @task client socket
// @task common push-pull transporter (serializacja ?)
// @task thread r/w
