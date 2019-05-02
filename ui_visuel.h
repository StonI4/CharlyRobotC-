/********************************************************************************
** Form generated from reading UI file 'visuel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUEL_H
#define UI_VISUEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Visuel
{
public:

    void setupUi(QDialog *Visuel)
    {
        if (Visuel->objectName().isEmpty())
            Visuel->setObjectName(QString::fromUtf8("Visuel"));
        Visuel->resize(300, 200);

        retranslateUi(Visuel);

        QMetaObject::connectSlotsByName(Visuel);
    } // setupUi

    void retranslateUi(QDialog *Visuel)
    {
        Visuel->setWindowTitle(QApplication::translate("Visuel", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Visuel: public Ui_Visuel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUEL_H
