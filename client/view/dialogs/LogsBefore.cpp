//
// Created by piotr@janczura.pl on 2019.12.30
//

#include "LogsBefore.h"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

#include "common/def.h"

namespace cl::view::dialog {


LogsBefore::LogsBefore(QWidget *parent)
    : QDialog(parent)
    , labelMoment(QLabel("Data graniczna", this))
    , dateTime()
    , okButton(QPushButton("OK"))
    , cancelButton(QPushButton("Cancel"))
{
    setWindowTitle("Pokaż logi przed datą");
    dateTime.setDisplayFormat(cm::DATE_TIME_TEMPLATE.c_str());
    dateTime.setDateTime(QDateTime::currentDateTime());

    layout();

    connect(&okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(&cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

}

void LogsBefore::layout()
{
    QGridLayout *gLayout = new QGridLayout;
    gLayout->setColumnStretch(2, 1);
    gLayout->addWidget(&labelMoment, 0, 0);
    gLayout->addWidget(&dateTime, 0, 1);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(&okButton);
    buttonLayout->addWidget(&cancelButton);

    gLayout->addLayout(buttonLayout, 1, 0);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);
}

}