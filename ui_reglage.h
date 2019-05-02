/********************************************************************************
** Form generated from reading UI file 'reglage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGLAGE_H
#define UI_REGLAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Reglage
{
public:
    QPushButton *Valider_Plaque;
    QLabel *Texte_Larg_Plaque;
    QDoubleSpinBox *Largeur_Plaque;
    QDoubleSpinBox *Epaisseur_Plaque;
    QDoubleSpinBox *Longueur_Plaque;
    QLabel *Texte_Epais_Plaque;
    QLabel *Texte_Long_Plaque;

    void setupUi(QDialog *Reglage)
    {
        if (Reglage->objectName().isEmpty())
            Reglage->setObjectName(QString::fromUtf8("Reglage"));
        Reglage->resize(390, 182);
        Reglage->setStyleSheet(QString::fromUtf8("background : rgb(77, 86, 86  );\n"
"color : rgb(255,255,250);\n"
"font-family: \"New Century Schoolbook\" ;"));
        Valider_Plaque = new QPushButton(Reglage);
        Valider_Plaque->setObjectName(QString::fromUtf8("Valider_Plaque"));
        Valider_Plaque->setGeometry(QRect(270, 130, 111, 41));
        Valider_Plaque->setStyleSheet(QString::fromUtf8("#Valider_Plaque{\n"
"background: rgb(52, 152, 219);\n"
"border-radius:5px;\n"
" }\n"
"#Valider_Plaque::hover { \n"
"background : rgb(21, 67, 96 );\n"
"color:white;\n"
"}\n"
""));
        Texte_Larg_Plaque = new QLabel(Reglage);
        Texte_Larg_Plaque->setObjectName(QString::fromUtf8("Texte_Larg_Plaque"));
        Texte_Larg_Plaque->setGeometry(QRect(30, 10, 131, 41));
        Texte_Larg_Plaque->setStyleSheet(QString::fromUtf8(""));
        Largeur_Plaque = new QDoubleSpinBox(Reglage);
        Largeur_Plaque->setObjectName(QString::fromUtf8("Largeur_Plaque"));
        Largeur_Plaque->setGeometry(QRect(180, 20, 62, 22));
        Epaisseur_Plaque = new QDoubleSpinBox(Reglage);
        Epaisseur_Plaque->setObjectName(QString::fromUtf8("Epaisseur_Plaque"));
        Epaisseur_Plaque->setGeometry(QRect(180, 60, 62, 22));
        Longueur_Plaque = new QDoubleSpinBox(Reglage);
        Longueur_Plaque->setObjectName(QString::fromUtf8("Longueur_Plaque"));
        Longueur_Plaque->setGeometry(QRect(180, 110, 62, 22));
        Texte_Epais_Plaque = new QLabel(Reglage);
        Texte_Epais_Plaque->setObjectName(QString::fromUtf8("Texte_Epais_Plaque"));
        Texte_Epais_Plaque->setGeometry(QRect(30, 50, 141, 41));
        Texte_Long_Plaque = new QLabel(Reglage);
        Texte_Long_Plaque->setObjectName(QString::fromUtf8("Texte_Long_Plaque"));
        Texte_Long_Plaque->setGeometry(QRect(20, 100, 141, 41));

        retranslateUi(Reglage);

        QMetaObject::connectSlotsByName(Reglage);
    } // setupUi

    void retranslateUi(QDialog *Reglage)
    {
        Reglage->setWindowTitle(QApplication::translate("Reglage", "Dialog", nullptr));
        Valider_Plaque->setText(QApplication::translate("Reglage", "Valider", nullptr));
        Texte_Larg_Plaque->setText(QApplication::translate("Reglage", "Largeur de la Plaque (mm)", nullptr));
        Texte_Epais_Plaque->setText(QApplication::translate("Reglage", "Epaisseur de la Plaque (mm)", nullptr));
        Texte_Long_Plaque->setText(QApplication::translate("Reglage", "Longueur  de la Plaque (mm)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reglage: public Ui_Reglage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGLAGE_H
