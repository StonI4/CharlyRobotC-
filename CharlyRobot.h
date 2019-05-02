#ifndef CHARLYROBOT_H
#define CHARLYROBOT_H

#include <QMainWindow>
#include <qabstractslider.h>
#include <qlabel.h>
#include <QtCore>
#include <QtGui>
#include <qfilesystemmodel.h>
#include <QSlider>
#include "filtreDxf.h"
#include "PilotageCharlyRobot.h"
#include <vector>
#include <QtSerialPort>
#include <qthread.h>


namespace Ui {
class CharlyRobot;
}

class CharlyRobot : public QMainWindow
{
    Q_OBJECT

public:
    explicit CharlyRobot(QWidget *parent = 0);
    ~CharlyRobot();
    filtreDxf *myfilter;
    PilotageCharlyRobot *data;
    QSlider* DeplacementX_2;
    QSlider* DeplacementY_2;
    QSlider* DeplacementZ_2;
    void DeplacementManuelle();
    QString filename;
    void ReglagePlaque();
    void ReglageFraise();
    std::vector<float>Coordonnee;
    std::vector<int>CoordAbs;
    std::vector<std::string>Texte;
	bool Lettre;
    QString dfsd = " #menuFichier:hover{background:black;}";
    void ValiderOrigine();
    virtual void paintEvent(QPaintEvent *event);
    int X, Y, Z, V;
    vector<string>Trame;
    void reset();
	void error();
    void lancer();
    void envoietrame();
    void AffichageTPSReel(int a);
	void effaceRAM();
	void popupstyle();
	void connexionport();
	void deconnexionport();
	void OuvrirFichier();
	void view();
	void recupstyle();
private:
    Ui::CharlyRobot *ui;
    QSerialPort *serie;

};

#endif // CHARLYROBOT_H
