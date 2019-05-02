/********************************************************************************
** Form generated from reading UI file 'CharlyRobot.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARLYROBOT_H
#define UI_CHARLYROBOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CharlyRobot
{
public:
    QAction *Ouvrir;
    QAction *Plaque;
    QAction *Fraise;
    QWidget *centralWidget;
    QGroupBox *GroupeManu;
    QLabel *TexteY_2;
    QLabel *TexteX_2;
    QLabel *TexteZ_2;
    QSlider *DeplacementZ_2;
    QSlider *DeplacementX_2;
    QSlider *DeplacementY_2;
    QPushButton *ButtonPositionner;
    QSpinBox *Valeur_Z_2;
    QSpinBox *Valeur_X_2;
    QSpinBox *Valeur_Y_2;
    QSlider *Changement_Vitesse;
    QLabel *Texte_Manuelle_Vitesse;
    QLabel *mm;
    QLabel *mm_2;
    QLabel *mm_3;
    QSpinBox *Valeur_Manuelle_Vitesse;
    QPushButton *Valider_Origine;
    QPushButton *reset;
    QGroupBox *GroupeReel;
    QLabel *TexteReelX_2;
    QLabel *TexteReelY_2;
    QLabel *TexteReelZ_2;
    QLabel *ValeurReelX_2;
    QLabel *ValeurReelY_2;
    QLabel *ValeurReelZ_2;
    QLabel *Valeur_Reel_Vitesse;
    QLabel *Texte_Reel_Vitesse;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_2;
    QPushButton *Demarrer;
    QComboBox *listcom;
    QLabel *label;
    QLabel *Texte_FichierDXF;
    QPushButton *Boutton_Visuel;
    QLabel *label_6;
    QPushButton *Deconnexion;
    QPushButton *Connexion;
    QLabel *state;
    QGroupBox *groupBox;
    QLabel *X_Origine;
    QLabel *Y_Origine;
    QLabel *label_8;
    QLabel *Valeur_X_Origine;
    QLabel *Valeur_Y_Origine;
    QLabel *Valeur_Z_Origine;
    QPushButton *effme;
    QLabel *label_7;
    QLabel *l_police;
    QComboBox *c_police;
    QPushButton *b_police;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuOptions;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CharlyRobot)
    {
        if (CharlyRobot->objectName().isEmpty())
            CharlyRobot->setObjectName(QString::fromUtf8("CharlyRobot"));
        CharlyRobot->resize(1195, 626);
        CharlyRobot->setStyleSheet(QString::fromUtf8(""));
        Ouvrir = new QAction(CharlyRobot);
        Ouvrir->setObjectName(QString::fromUtf8("Ouvrir"));
        Plaque = new QAction(CharlyRobot);
        Plaque->setObjectName(QString::fromUtf8("Plaque"));
        Fraise = new QAction(CharlyRobot);
        Fraise->setObjectName(QString::fromUtf8("Fraise"));
        centralWidget = new QWidget(CharlyRobot);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GroupeManu = new QGroupBox(centralWidget);
        GroupeManu->setObjectName(QString::fromUtf8("GroupeManu"));
        GroupeManu->setGeometry(QRect(630, 190, 501, 291));
        GroupeManu->setStyleSheet(QString::fromUtf8(""));
        TexteY_2 = new QLabel(GroupeManu);
        TexteY_2->setObjectName(QString::fromUtf8("TexteY_2"));
        TexteY_2->setGeometry(QRect(240, 80, 31, 16));
        TexteX_2 = new QLabel(GroupeManu);
        TexteX_2->setObjectName(QString::fromUtf8("TexteX_2"));
        TexteX_2->setGeometry(QRect(240, 40, 31, 16));
        TexteZ_2 = new QLabel(GroupeManu);
        TexteZ_2->setObjectName(QString::fromUtf8("TexteZ_2"));
        TexteZ_2->setGeometry(QRect(50, 20, 31, 16));
        DeplacementZ_2 = new QSlider(GroupeManu);
        DeplacementZ_2->setObjectName(QString::fromUtf8("DeplacementZ_2"));
        DeplacementZ_2->setGeometry(QRect(20, 20, 21, 251));
        DeplacementZ_2->setStyleSheet(QString::fromUtf8(""));
        DeplacementZ_2->setMaximum(95);
        DeplacementZ_2->setTracking(true);
        DeplacementZ_2->setOrientation(Qt::Vertical);
        DeplacementZ_2->setInvertedAppearance(true);
        DeplacementZ_2->setInvertedControls(false);
        DeplacementX_2 = new QSlider(GroupeManu);
        DeplacementX_2->setObjectName(QString::fromUtf8("DeplacementX_2"));
        DeplacementX_2->setGeometry(QRect(70, 60, 401, 20));
        DeplacementX_2->setStyleSheet(QString::fromUtf8(""));
        DeplacementX_2->setMaximum(280);
        DeplacementX_2->setOrientation(Qt::Horizontal);
        DeplacementY_2 = new QSlider(GroupeManu);
        DeplacementY_2->setObjectName(QString::fromUtf8("DeplacementY_2"));
        DeplacementY_2->setGeometry(QRect(70, 100, 401, 20));
        DeplacementY_2->setMaximum(160);
        DeplacementY_2->setOrientation(Qt::Horizontal);
        ButtonPositionner = new QPushButton(GroupeManu);
        ButtonPositionner->setObjectName(QString::fromUtf8("ButtonPositionner"));
        ButtonPositionner->setGeometry(QRect(70, 200, 81, 31));
        ButtonPositionner->setStyleSheet(QString::fromUtf8("#ButtonPositionner{\n"
"background: rgb(52, 152, 219);\n"
"border-radius:5px;\n"
" }\n"
"#ButtonPositionner::hover { \n"
"background : rgb(21, 67, 96 );\n"
"color:white;\n"
"}\n"
""));
        Valeur_Z_2 = new QSpinBox(GroupeManu);
        Valeur_Z_2->setObjectName(QString::fromUtf8("Valeur_Z_2"));
        Valeur_Z_2->setGeometry(QRect(70, 20, 42, 22));
        Valeur_Z_2->setStyleSheet(QString::fromUtf8("background:#fff;\n"
"color: black;"));
        Valeur_Z_2->setMaximum(100);
        Valeur_X_2 = new QSpinBox(GroupeManu);
        Valeur_X_2->setObjectName(QString::fromUtf8("Valeur_X_2"));
        Valeur_X_2->setGeometry(QRect(260, 40, 42, 22));
        QFont font;
        font.setFamily(QString::fromUtf8("New Century Schoolbook"));
        Valeur_X_2->setFont(font);
        Valeur_X_2->setStyleSheet(QString::fromUtf8("background:#fff;\n"
"color: black;"));
        Valeur_X_2->setMaximum(280);
        Valeur_Y_2 = new QSpinBox(GroupeManu);
        Valeur_Y_2->setObjectName(QString::fromUtf8("Valeur_Y_2"));
        Valeur_Y_2->setGeometry(QRect(260, 80, 42, 22));
        Valeur_Y_2->setStyleSheet(QString::fromUtf8("background:#fff;\n"
"color: black;"));
        Valeur_Y_2->setMaximum(300);
        Changement_Vitesse = new QSlider(GroupeManu);
        Changement_Vitesse->setObjectName(QString::fromUtf8("Changement_Vitesse"));
        Changement_Vitesse->setGeometry(QRect(70, 150, 401, 20));
        Changement_Vitesse->setMinimum(1000);
        Changement_Vitesse->setMaximum(2000);
        Changement_Vitesse->setOrientation(Qt::Horizontal);
        Texte_Manuelle_Vitesse = new QLabel(GroupeManu);
        Texte_Manuelle_Vitesse->setObjectName(QString::fromUtf8("Texte_Manuelle_Vitesse"));
        Texte_Manuelle_Vitesse->setGeometry(QRect(210, 130, 47, 13));
        Texte_Manuelle_Vitesse->setStyleSheet(QString::fromUtf8(""));
        mm = new QLabel(GroupeManu);
        mm->setObjectName(QString::fromUtf8("mm"));
        mm->setGeometry(QRect(310, 40, 47, 13));
        mm->setFont(font);
        mm_2 = new QLabel(GroupeManu);
        mm_2->setObjectName(QString::fromUtf8("mm_2"));
        mm_2->setGeometry(QRect(310, 80, 47, 13));
        mm_2->setFont(font);
        mm_2->setStyleSheet(QString::fromUtf8(""));
        mm_3 = new QLabel(GroupeManu);
        mm_3->setObjectName(QString::fromUtf8("mm_3"));
        mm_3->setGeometry(QRect(120, 30, 47, 13));
        Valeur_Manuelle_Vitesse = new QSpinBox(GroupeManu);
        Valeur_Manuelle_Vitesse->setObjectName(QString::fromUtf8("Valeur_Manuelle_Vitesse"));
        Valeur_Manuelle_Vitesse->setGeometry(QRect(260, 120, 42, 22));
        Valeur_Manuelle_Vitesse->setStyleSheet(QString::fromUtf8("background:#fff;\n"
"color: black;"));
        Valeur_Manuelle_Vitesse->setMinimum(1000);
        Valeur_Manuelle_Vitesse->setMaximum(2000);
        Valider_Origine = new QPushButton(GroupeManu);
        Valider_Origine->setObjectName(QString::fromUtf8("Valider_Origine"));
        Valider_Origine->setGeometry(QRect(320, 200, 151, 31));
        Valider_Origine->setStyleSheet(QString::fromUtf8("#Valider_Origine{\n"
"background: rgb(52, 152, 219);\n"
"border-radius:5px;\n"
" }\n"
"#Valider_Origine::hover { \n"
"background : rgb(21, 67, 96 );\n"
"color:white;\n"
"}\n"
""));
        reset = new QPushButton(GroupeManu);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setGeometry(QRect(184, 200, 101, 31));
        reset->setStyleSheet(QString::fromUtf8("#reset{\n"
"background: rgb(52, 152, 219);\n"
"border-radius:5px;\n"
" }\n"
"#reset::hover { \n"
"background : rgb(21, 67, 96 );\n"
"color:white;\n"
"}\n"
""));
        GroupeReel = new QGroupBox(centralWidget);
        GroupeReel->setObjectName(QString::fromUtf8("GroupeReel"));
        GroupeReel->setGeometry(QRect(630, 20, 311, 151));
        GroupeReel->setFont(font);
        TexteReelX_2 = new QLabel(GroupeReel);
        TexteReelX_2->setObjectName(QString::fromUtf8("TexteReelX_2"));
        TexteReelX_2->setGeometry(QRect(100, 30, 47, 13));
        TexteReelY_2 = new QLabel(GroupeReel);
        TexteReelY_2->setObjectName(QString::fromUtf8("TexteReelY_2"));
        TexteReelY_2->setGeometry(QRect(100, 50, 47, 13));
        TexteReelZ_2 = new QLabel(GroupeReel);
        TexteReelZ_2->setObjectName(QString::fromUtf8("TexteReelZ_2"));
        TexteReelZ_2->setGeometry(QRect(100, 70, 47, 13));
        ValeurReelX_2 = new QLabel(GroupeReel);
        ValeurReelX_2->setObjectName(QString::fromUtf8("ValeurReelX_2"));
        ValeurReelX_2->setGeometry(QRect(150, 30, 47, 13));
        ValeurReelY_2 = new QLabel(GroupeReel);
        ValeurReelY_2->setObjectName(QString::fromUtf8("ValeurReelY_2"));
        ValeurReelY_2->setGeometry(QRect(150, 50, 47, 13));
        ValeurReelZ_2 = new QLabel(GroupeReel);
        ValeurReelZ_2->setObjectName(QString::fromUtf8("ValeurReelZ_2"));
        ValeurReelZ_2->setGeometry(QRect(150, 70, 47, 13));
        Valeur_Reel_Vitesse = new QLabel(GroupeReel);
        Valeur_Reel_Vitesse->setObjectName(QString::fromUtf8("Valeur_Reel_Vitesse"));
        Valeur_Reel_Vitesse->setGeometry(QRect(140, 90, 41, 16));
        Texte_Reel_Vitesse = new QLabel(GroupeReel);
        Texte_Reel_Vitesse->setObjectName(QString::fromUtf8("Texte_Reel_Vitesse"));
        Texte_Reel_Vitesse->setGeometry(QRect(10, 90, 131, 21));
        label_3 = new QLabel(GroupeReel);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 30, 47, 13));
        label_4 = new QLabel(GroupeReel);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 50, 47, 13));
        label_5 = new QLabel(GroupeReel);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(180, 70, 47, 13));
        label_2 = new QLabel(GroupeReel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 90, 47, 13));
        Demarrer = new QPushButton(centralWidget);
        Demarrer->setObjectName(QString::fromUtf8("Demarrer"));
        Demarrer->setGeometry(QRect(990, 500, 141, 61));
        Demarrer->setStyleSheet(QString::fromUtf8("#Demarrer{\n"
"background: rgb(52, 152, 219);\n"
"border-radius:5px;\n"
"	font: 87 9pt \"Arial Black\";\n"
" }\n"
"#Demarrer::hover { \n"
"background : rgb(21, 67, 96 );\n"
"color:white;\n"
"}\n"
""));
        listcom = new QComboBox(centralWidget);
        listcom->setObjectName(QString::fromUtf8("listcom"));
        listcom->setGeometry(QRect(100, 530, 69, 22));
        listcom->setStyleSheet(QString::fromUtf8("background: grey;"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 530, 61, 20));
        label->setFont(font);
        Texte_FichierDXF = new QLabel(centralWidget);
        Texte_FichierDXF->setObjectName(QString::fromUtf8("Texte_FichierDXF"));
        Texte_FichierDXF->setGeometry(QRect(20, 50, 171, 21));
        Texte_FichierDXF->setStyleSheet(QString::fromUtf8("font-family: Arial;\n"
"font-size:12px;"));
        Boutton_Visuel = new QPushButton(centralWidget);
        Boutton_Visuel->setObjectName(QString::fromUtf8("Boutton_Visuel"));
        Boutton_Visuel->setGeometry(QRect(200, 40, 131, 31));
        Boutton_Visuel->setStyleSheet(QString::fromUtf8("\n"
"#Boutton_Visuel{\n"
"background: rgb(52, 152, 219);\n"
"border-radius:5px;\n"
" }\n"
"#Boutton_Visuel::hover { \n"
"background : rgb(21, 67, 96 );\n"
"color:white;\n"
"}\n"
"\n"
""));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(260, 200, 121, 21));
        label_6->setFont(font);
        Deconnexion = new QPushButton(centralWidget);
        Deconnexion->setObjectName(QString::fromUtf8("Deconnexion"));
        Deconnexion->setEnabled(false);
        Deconnexion->setGeometry(QRect(270, 530, 81, 23));
        Deconnexion->setStyleSheet(QString::fromUtf8("\n"
"#Deconnexion{\n"
"background: rgb(52, 152, 219);\n"
"border-radius:5px;\n"
"	font: 9pt \"Arial\";\n"
" }\n"
"\n"
"\n"
"#Deconnexion::hover{ \n"
"background : rgb(21, 67, 96 );\n"
"color:white;\n"
"}\n"
""));
        Connexion = new QPushButton(centralWidget);
        Connexion->setObjectName(QString::fromUtf8("Connexion"));
        Connexion->setGeometry(QRect(180, 530, 75, 23));
        Connexion->setStyleSheet(QString::fromUtf8("\n"
"#Connexion{\n"
"font: 9pt \"Arial\";\n"
"background: rgb(52, 152, 219);\n"
"border-radius:5px;\n"
" }\n"
"#Connexion::hover { \n"
"background : rgb(21, 67, 96 );\n"
"color:white;\n"
"}\n"
"\n"
""));
        state = new QLabel(centralWidget);
        state->setObjectName(QString::fromUtf8("state"));
        state->setGeometry(QRect(370, 532, 16, 16));
        state->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(950, 20, 181, 151));
        X_Origine = new QLabel(groupBox);
        X_Origine->setObjectName(QString::fromUtf8("X_Origine"));
        X_Origine->setGeometry(QRect(60, 40, 21, 16));
        Y_Origine = new QLabel(groupBox);
        Y_Origine->setObjectName(QString::fromUtf8("Y_Origine"));
        Y_Origine->setGeometry(QRect(60, 70, 16, 16));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(60, 100, 21, 16));
        Valeur_X_Origine = new QLabel(groupBox);
        Valeur_X_Origine->setObjectName(QString::fromUtf8("Valeur_X_Origine"));
        Valeur_X_Origine->setGeometry(QRect(80, 40, 47, 13));
        Valeur_Y_Origine = new QLabel(groupBox);
        Valeur_Y_Origine->setObjectName(QString::fromUtf8("Valeur_Y_Origine"));
        Valeur_Y_Origine->setGeometry(QRect(80, 70, 47, 20));
        Valeur_Z_Origine = new QLabel(groupBox);
        Valeur_Z_Origine->setObjectName(QString::fromUtf8("Valeur_Z_Origine"));
        Valeur_Z_Origine->setGeometry(QRect(80, 100, 47, 13));
        effme = new QPushButton(centralWidget);
        effme->setObjectName(QString::fromUtf8("effme"));
        effme->setGeometry(QRect(730, 490, 111, 41));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(540, 512, 151, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Berlin Sans FB"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_7->setFont(font1);
        l_police = new QLabel(centralWidget);
        l_police->setObjectName(QString::fromUtf8("l_police"));
        l_police->setEnabled(true);
        l_police->setGeometry(QRect(350, 50, 71, 21));
        c_police = new QComboBox(centralWidget);
        c_police->addItem(QString());
        c_police->addItem(QString());
        c_police->addItem(QString());
        c_police->addItem(QString());
        c_police->addItem(QString());
        c_police->setObjectName(QString::fromUtf8("c_police"));
        c_police->setGeometry(QRect(420, 50, 111, 21));
        b_police = new QPushButton(centralWidget);
        b_police->setObjectName(QString::fromUtf8("b_police"));
        b_police->setGeometry(QRect(540, 50, 75, 23));
        CharlyRobot->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CharlyRobot);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1195, 21));
        menuBar->setStyleSheet(QString::fromUtf8("#menuBar{\n"
" background:rgb(59, 64, 61  );	\n"
"color : white;\n"
"   }\n"
"#menuBar::item:selected { \n"
"background : rgb(77, 86, 86  );;\n"
"color:white;\n"
"}\n"
"\n"
""));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuFichier->setStyleSheet(QString::fromUtf8("#menuFichier{\n"
" background:rgb(59, 64, 61  );	\n"
"color : white;\n"
"border-bottom:2px;\n"
"   }\n"
"#menuFichier::item:selected { \n"
"background : rgb(77, 86, 86  );;\n"
"color:white;\n"
"}\n"
"\n"
""));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuOptions->setStyleSheet(QString::fromUtf8("#menuOptions{\n"
" background:rgb(59, 64, 61  );	\n"
"color : white;\n"
"border-bottom:2px;\n"
"   }\n"
"#menuOptions::item:selected { \n"
"background : rgb(77, 86, 86  );;\n"
"color:white;\n"
"}\n"
""));
        CharlyRobot->setMenuBar(menuBar);
        statusBar = new QStatusBar(CharlyRobot);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CharlyRobot->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuFichier->addAction(Ouvrir);
        menuOptions->addAction(Plaque);
        menuOptions->addAction(Fraise);

        retranslateUi(CharlyRobot);
        QObject::connect(DeplacementZ_2, SIGNAL(sliderMoved(int)), Valeur_Z_2, SLOT(setValue(int)));
        QObject::connect(DeplacementX_2, SIGNAL(sliderMoved(int)), Valeur_X_2, SLOT(setValue(int)));
        QObject::connect(DeplacementY_2, SIGNAL(sliderMoved(int)), Valeur_Y_2, SLOT(setValue(int)));
        QObject::connect(Valeur_Z_2, SIGNAL(valueChanged(int)), DeplacementZ_2, SLOT(setValue(int)));
        QObject::connect(Valeur_X_2, SIGNAL(valueChanged(int)), DeplacementX_2, SLOT(setValue(int)));
        QObject::connect(Valeur_Y_2, SIGNAL(valueChanged(int)), DeplacementY_2, SLOT(setValue(int)));
        QObject::connect(DeplacementZ_2, SIGNAL(valueChanged(int)), Valeur_Z_2, SLOT(setValue(int)));
        QObject::connect(DeplacementX_2, SIGNAL(valueChanged(int)), Valeur_X_2, SLOT(setValue(int)));
        QObject::connect(DeplacementY_2, SIGNAL(valueChanged(int)), Valeur_Y_2, SLOT(setValue(int)));
        QObject::connect(Changement_Vitesse, SIGNAL(sliderMoved(int)), Valeur_Manuelle_Vitesse, SLOT(setValue(int)));
        QObject::connect(Valeur_Manuelle_Vitesse, SIGNAL(valueChanged(int)), Changement_Vitesse, SLOT(setValue(int)));
        QObject::connect(Changement_Vitesse, SIGNAL(valueChanged(int)), Valeur_Manuelle_Vitesse, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(CharlyRobot);
    } // setupUi

    void retranslateUi(QMainWindow *CharlyRobot)
    {
        CharlyRobot->setWindowTitle(QApplication::translate("CharlyRobot", "CharlyRobot", nullptr));
        Ouvrir->setText(QApplication::translate("CharlyRobot", "Ouvrir", nullptr));
        Plaque->setText(QApplication::translate("CharlyRobot", "Reglage Plaque", nullptr));
        Fraise->setText(QApplication::translate("CharlyRobot", "Reglage Fraise", nullptr));
        GroupeManu->setTitle(QApplication::translate("CharlyRobot", "                                                 Gestion Manuelle de CHARLYROBOT :", nullptr));
        TexteY_2->setText(QApplication::translate("CharlyRobot", "Y :", nullptr));
        TexteX_2->setText(QApplication::translate("CharlyRobot", "X :", nullptr));
        TexteZ_2->setText(QApplication::translate("CharlyRobot", "Z :", nullptr));
        ButtonPositionner->setText(QApplication::translate("CharlyRobot", "Positionner", nullptr));
        Texte_Manuelle_Vitesse->setText(QApplication::translate("CharlyRobot", "Vitesse :", nullptr));
        mm->setText(QApplication::translate("CharlyRobot", "mm", nullptr));
        mm_2->setText(QApplication::translate("CharlyRobot", "mm", nullptr));
        mm_3->setText(QApplication::translate("CharlyRobot", "mm", nullptr));
        Valider_Origine->setText(QApplication::translate("CharlyRobot", "Validation Point D'origine", nullptr));
        reset->setText(QApplication::translate("CharlyRobot", "R\303\251initialiser", nullptr));
        GroupeReel->setTitle(QApplication::translate("CharlyRobot", "         CHARLYROBOT : Coordonn\303\251es en temps r\303\251el. ", nullptr));
        TexteReelX_2->setText(QApplication::translate("CharlyRobot", "X :", nullptr));
        TexteReelY_2->setText(QApplication::translate("CharlyRobot", "Y :", nullptr));
        TexteReelZ_2->setText(QApplication::translate("CharlyRobot", "Z :", nullptr));
        ValeurReelX_2->setText(QApplication::translate("CharlyRobot", "000", nullptr));
        ValeurReelY_2->setText(QApplication::translate("CharlyRobot", "000", nullptr));
        ValeurReelZ_2->setText(QApplication::translate("CharlyRobot", "000", nullptr));
        Valeur_Reel_Vitesse->setText(QApplication::translate("CharlyRobot", "000", nullptr));
        Texte_Reel_Vitesse->setText(QApplication::translate("CharlyRobot", "Vitesse de d\303\251placement :", nullptr));
        label_3->setText(QApplication::translate("CharlyRobot", "mm", nullptr));
        label_4->setText(QApplication::translate("CharlyRobot", "mm", nullptr));
        label_5->setText(QApplication::translate("CharlyRobot", "mm", nullptr));
        label_2->setText(QApplication::translate("CharlyRobot", "tr/s", nullptr));
        Demarrer->setText(QApplication::translate("CharlyRobot", "D\303\251marrer ", nullptr));
        label->setText(QApplication::translate("CharlyRobot", "Port COM: ", nullptr));
        Texte_FichierDXF->setText(QApplication::translate("CharlyRobot", "Fichier DXF ouvert avec succ\303\250s :", nullptr));
        Boutton_Visuel->setText(QApplication::translate("CharlyRobot", "Visuel De La Gravure", nullptr));
        label_6->setText(QApplication::translate("CharlyRobot", "Suivi de la Fraise : ", nullptr));
        Deconnexion->setText(QApplication::translate("CharlyRobot", "D\303\251connexion", nullptr));
        Connexion->setText(QApplication::translate("CharlyRobot", "Connexion", nullptr));
        state->setText(QString());
        groupBox->setTitle(QApplication::translate("CharlyRobot", "Point D'origine", nullptr));
        X_Origine->setText(QApplication::translate("CharlyRobot", "X : ", nullptr));
        Y_Origine->setText(QApplication::translate("CharlyRobot", "Y :", nullptr));
        label_8->setText(QApplication::translate("CharlyRobot", "Z :", nullptr));
        Valeur_X_Origine->setText(QApplication::translate("CharlyRobot", "000", nullptr));
        Valeur_Y_Origine->setText(QApplication::translate("CharlyRobot", "000", nullptr));
        Valeur_Z_Origine->setText(QApplication::translate("CharlyRobot", "000", nullptr));
        effme->setText(QApplication::translate("CharlyRobot", "Efface m\303\251moire", nullptr));
        label_7->setText(QApplication::translate("CharlyRobot", "TextLabel", nullptr));
        l_police->setText(QApplication::translate("CharlyRobot", "Saisie police :", nullptr));
        c_police->setItemText(0, QApplication::translate("CharlyRobot", "Arial", nullptr));
        c_police->setItemText(1, QApplication::translate("CharlyRobot", "Futura", nullptr));
        c_police->setItemText(2, QApplication::translate("CharlyRobot", "Blackadder", nullptr));
        c_police->setItemText(3, QApplication::translate("CharlyRobot", "Tmes New Roman", nullptr));
        c_police->setItemText(4, QApplication::translate("CharlyRobot", "Verdana", nullptr));

        b_police->setText(QApplication::translate("CharlyRobot", "Valider", nullptr));
        menuFichier->setTitle(QApplication::translate("CharlyRobot", "Fichier", nullptr));
        menuOptions->setTitle(QApplication::translate("CharlyRobot", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CharlyRobot: public Ui_CharlyRobot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARLYROBOT_H
