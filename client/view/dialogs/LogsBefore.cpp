//
// Created by piotr@janczura.pl on 2019.12.30
//

#include "LogsBefore.h"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

namespace cl::view::dialog {


LogsBefore::LogsBefore(QWidget *parent)
    : QDialog(parent)
    , info(QLabel("W BUDOWIE", this))
    , okButton(QPushButton("OK"))
    , cancelButton(QPushButton("Cancel"))
{
    setWindowTitle("Pokaż logi przed datą");
    layout();

    connect(&okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(&cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

}

void LogsBefore::layout()
{
    QGridLayout *gLayout = new QGridLayout;
    gLayout->setColumnStretch(2, 1);
    gLayout->addWidget(&info, 0, 0);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(&okButton);
    buttonLayout->addWidget(&cancelButton);

    gLayout->addLayout(buttonLayout, 1, 0);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);
}

}