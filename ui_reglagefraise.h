/********************************************************************************
** Form generated from reading UI file 'reglagefraise.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGLAGEFRAISE_H
#define UI_REGLAGEFRAISE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_reglagefraise
{
public:
    QPushButton *Valider_Fraise;
    QLabel *Texte_Longeur_Fraise;
    QLabel *Texte_Epaisseur_Fraise;
    QDoubleSpinBox *Valeur_Longeur_Fraise;
    QDoubleSpinBox *Valeur_Epaisseur_Fraise;

    void setupUi(QDialog *reglagefraise)
    {
        if (reglagefraise->objectName().isEmpty())
            reglagefraise->setObjectName(QString::fromUtf8("reglagefraise"));
        reglagefraise->resize(309, 227);
        reglagefraise->setStyleSheet(QString::fromUtf8("background : rgb(77, 86, 86  );\n"
"color: white;"));
        Valider_Fraise = new QPushButton(reglagefraise);
        Valider_Fraise->setObjectName(QString::fromUtf8("Valider_Fraise"));
        Valider_Fraise->setGeometry(QRect(190, 170, 111, 41));
        Valider_Fraise->setStyleSheet(QString::fromUtf8("#Valider_Fraise{\n"
"background: rgb(52, 152, 219);\n"
"border-radius:5px;\n"
" }\n"
"#Valider_Fraise::hover { \n"
"background : rgb(21, 67, 96 );\n"
"color:white;\n"
"}\n"
""));
        Texte_Longeur_Fraise = new QLabel(reglagefraise);
        Texte_Longeur_Fraise->setObjectName(QString::fromUtf8("Texte_Longeur_Fraise"));
        Texte_Longeur_Fraise->setGeometry(QRect(10, 20, 131, 21));
        Texte_Epaisseur_Fraise = new QLabel(reglagefraise);
        Texte_Epaisseur_Fraise->setObjectName(QString::fromUtf8("Texte_Epaisseur_Fraise"));
        Texte_Epaisseur_Fraise->setGeometry(QRect(10, 80, 141, 21));
        Valeur_Longeur_Fraise = new QDoubleSpinBox(reglagefraise);
        Valeur_Longeur_Fraise->setObjectName(QString::fromUtf8("Valeur_Longeur_Fraise"));
        Valeur_Longeur_Fraise->setGeometry(QRect(160, 20, 62, 22));
        Valeur_Epaisseur_Fraise = new QDoubleSpinBox(reglagefraise);
        Valeur_Epaisseur_Fraise->setObjectName(QString::fromUtf8("Valeur_Epaisseur_Fraise"));
        Valeur_Epaisseur_Fraise->setGeometry(QRect(160, 80, 62, 22));

        retranslateUi(reglagefraise);

        QMetaObject::connectSlotsByName(reglagefraise);
    } // setupUi

    void retranslateUi(QDialog *reglagefraise)
    {
        reglagefraise->setWindowTitle(QApplication::translate("reglagefraise", "Dialog", nullptr));
        Valider_Fraise->setText(QApplication::translate("reglagefraise", "Valider", nullptr));
        Texte_Longeur_Fraise->setText(QApplication::translate("reglagefraise", "Longeur de la Fraise (mm)", nullptr));
        Texte_Epaisseur_Fraise->setText(QApplication::translate("reglagefraise", "Epaisseur de la Fraise (mm)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reglagefraise: public Ui_reglagefraise {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGLAGEFRAISE_H
