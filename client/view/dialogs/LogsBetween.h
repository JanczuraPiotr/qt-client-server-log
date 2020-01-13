//
// Created by piotr@janczura.pl on 2019.12.30
//

#ifndef CLIENT_DIALOG_LOGSBETWEEN
#define CLIENT_DIALOG_LOGSBETWEEN

#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include "common/def.h"


namespace cl::view::dialog {

class LogsBetween : public QDialog{
Q_OBJECT
public:
    explicit LogsBetween(QWidget *parent = nullptr);

    cm::DateTime getBorderEarlier();
    cm::DateTime getBorderLatter();

private: // methods
    void layout();

private: // attributes
    QLabel labelEarlier;
    QLabel labelLatter;
    QDateTimeEdit borderEarlier;
    QDateTimeEdit borderLatter;
    QPushButton okButton;
    QPushButton cancelButton;

};
}


#endif
