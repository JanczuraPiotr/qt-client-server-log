//
// Created by piotr@janczura.pl on 2019.12.30
//

#include "LogsBetween.h"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

#include "common/def.h"

namespace cl::view::dialog {

LogsBetween::LogsBetween(QWidget *parent)
    : QDialog(parent)
    , labelEarlier(QLabel("Data początkowa", this))
    , labelLatter(QLabel("Data końcowa", this))
    , borderEarlier()
    , borderLatter()
    , okButton(QPushButton("OK"))
    , cancelButton(QPushButton("Cancel"))
{
    setWindowTitle("Pokaż logi między datami");
    borderEarlier.setDisplayFormat(cm::DATE_TIME_TEMPLATE.c_str());
    borderEarlier.setDateTime(QDateTime::currentDateTime());
    borderLatter.setDisplayFormat(cm::DATE_TIME_TEMPLATE.c_str());
    borderLatter.setDateTime(QDateTime::currentDateTime());

    layout();

    connect(&okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(&cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

}

void LogsBetween::layout()
{
    QGridLayout *gLayout = new QGridLayout;
    gLayout->setColumnStretch(3, 1);
    gLayout->addWidget(&labelEarlier, 0, 0);
    gLayout->addWidget(&borderEarlier, 0, 1);
    gLayout->addWidget(&labelLatter, 1, 0);
    gLayout->addWidget(&borderLatter, 1, 1);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(&okButton);
    buttonLayout->addWidget(&cancelButton);

    gLayout->addLayout(buttonLayout, 2, 0);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);
}

QString LogsBetween::getBorderEarlier()
{
    return borderEarlier.text();
}

QString LogsBetween::getBorderLatter()
{
    return borderLatter.text();
}


}