//
// Created by piotr@janczura.pl on 2019.04.13
//

#include <QCoreApplication>
#include <iostream>
#include <QDebug>

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);
    qDebug() << "client ";
    std::cout << "client" << std::endl;
    return 0;
}

// @task main window
// @task table
// @task table add
// @task table update
// @task table delete
// @task table search
// @task client socket
// @task common push-pull transporter (serializacja ?)
