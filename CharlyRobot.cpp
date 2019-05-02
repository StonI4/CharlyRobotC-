#include "CharlyRobot.h"
#include "ui_CharlyRobot.h"
#include <qabstractslider.h>
#include <qlabel.h>
#include <qstring.h>
#include <iostream>
#include <QFileDialog>
#include <qmessagebox.h>
#include "reglage.h"
#include "reglagefraise.h"
#include "QImage"
#include <QtPrintSupport/QPrinter>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "visuel.h"
#include "filtreDxf.h"
#include "PilotageCharlyRobot.h"
#include <thread>


CharlyRobot::CharlyRobot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CharlyRobot)
{
    ui->setupUi(this);
    serie = new QSerialPort(this);

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QString s = info.portName();
        ui->listcom->addItem(s);

    }

    connect(ui->reset, &QPushButton::clicked, this, &CharlyRobot::reset); // Réinitialise les valuers X, Y et Z à 0.
    connect(ui->ButtonPositionner, &QPushButton::clicked, this, &CharlyRobot::DeplacementManuelle); // Connection du Button Positionner à la Fonction "DeplacementManuelle"
    connect(ui->Ouvrir, &QAction::triggered, this, &CharlyRobot::OuvrirFichier); // Connection du Button Ouvrir à la Fonction "OuvrirFichier"
    connect(ui->Plaque, &QAction::triggered, this, &CharlyRobot::ReglagePlaque); // Connection du Button Réglage Plaque à la Fonction "ReglagePlaque"
    connect(ui->Fraise, &QAction::triggered, this, &CharlyRobot::ReglageFraise);
    connect(ui->Boutton_Visuel, &QPushButton::clicked, this, &CharlyRobot::view);// Visualitation du dessin avant la gravure
    connect(ui->Valider_Origine, &QPushButton::clicked, this, &CharlyRobot::ValiderOrigine);
    connect(ui->Connexion, &QPushButton::clicked, this, &CharlyRobot::connexionport); // Connection au Port
    connect(ui->Deconnexion, &QPushButton::clicked, this, &CharlyRobot::deconnexionport); // Déconnection du Port.
    connect(ui->Demarrer, &QPushButton::clicked, this, &CharlyRobot::lancer); // Lance la création des trames du fichier selectionné
	connect(ui->effme, &QPushButton::clicked, this, &CharlyRobot::effaceRAM);
	connect(ui->b_police, &QPushButton::clicked, this, &CharlyRobot::recupstyle);

    ui->GroupeManu->setStyleSheet(dfsd);
    ui->state->setStyleSheet("#state{background:red;border-radius:5px;}");

	ui->l_police->setVisible(false);
	ui->c_police->setVisible(false);
	ui->b_police->setVisible(false);
}

void CharlyRobot::connexionport()
{
    serie->setPortName(ui->listcom->currentText());
    serie->setBaudRate(QSerialPort::Baud9600);
    serie->setDataBits(QSerialPort::Data8);
    serie->setParity(QSerialPort::NoParity);
    serie->setStopBits(QSerialPort::OneStop);
    serie->setFlowControl(QSerialPort::NoFlowControl);

    if(serie->open(QIODevice::ReadWrite)) {
        ui->Connexion->setEnabled(false);
        ui->Deconnexion->setEnabled(true);
        ui->ButtonPositionner->setEnabled(true);
        ui->Demarrer->setEnabled(true);
        ui->state->setStyleSheet("#state{background:green;border-radius:5px;}");
    }
    else {

        int ret = QMessageBox::critical(this, tr("Erreur"),tr("Impossible d'ouvrir le Port"),QMessageBox::Close);
    }

}

void CharlyRobot::envoietrame()
{
    bool rep;
    QByteArray data;
    int reponse;
    for (int i = 0; i < Trame.size(); i++) {
        const char *trameenvoie = Trame[i].c_str(); //Transforme un string en char*
        serie->write(trameenvoie);
        serie->waitForBytesWritten();
        rep = serie->waitForReadyRead(10000);
        if (rep) {
            data = serie->readAll();
            reponse = data.toInt();
            switch (reponse)
            {
            case 0:
                ui->label_7->setText("Aucune erreur");
                break;
            break;
            case 1:
                ui->label_7->setText("Error: Transmission d'un nombre incorrect");
                return;
            case 2:
                ui->label_7->setText("Error: Fin de course");
                return;
            case 3:
                ui->label_7->setText("Error: Nombre d'axes inadmissible");
                return;
            case 4:
                ui->label_7->setText("Error: Pas d'axe defini");
                return;
            case 5:
                ui->label_7->setText("Error: Erreur de syntaxe");
                return;
            case 6:
                ui->label_7->setText("Error: Depassement de la capacite de memoire");
                return;
            case 7:
                ui->label_7->setText("Error: Nombre de paramètre inadmissible");
                return;
            case 8:
                ui->label_7->setText("Error: Memorisation incorrecte d'un ordre");
                return;
            default:
                ui->label_7->setText("Error: CharlyRobot n'a pas retourné de réponse au bout de 10 secondes");
                return;

            }
        }
    }
}


void CharlyRobot::deconnexionport()
{
    if (serie->isOpen())
        serie->close();
    ui->Connexion->setEnabled(true);
    ui->Deconnexion->setEnabled(false);
    ui->Demarrer->setEnabled(false);
    ui->ButtonPositionner->setEnabled(false);
    ui->state->setStyleSheet("#state{background:red;border-radius:5px;}");
}

void CharlyRobot::lancer()
{
    float x = X;
    float y = Y;
    float z = Z;
    int v = V;
	data = new PilotageCharlyRobot(Coordonnee, CoordAbs, Texte, x, y, z, v, Trame, Lettre);
    ui->Demarrer->setEnabled(false);
    data->launch();
	
    envoietrame();
    ui->Demarrer->setEnabled(true);
}

void CharlyRobot::DeplacementManuelle()
{

    X = ui->DeplacementX_2->value(); // récupère la valeur manuelle de X
    Y = ui->DeplacementY_2->value(); // récupère la valeur manuelle de Y
    Z = ui->DeplacementZ_2->value(); // récupère la valeur manuelle de Z
    V = ui->Changement_Vitesse->value(); // récupère la valeur manuelle de la vitesse

	QString afficheX = QString::number(X);
	QString afficheY = QString::number(Y);
	QString afficheZ = QString::number(Z);
	QString afficheV = QString::number(V);

    ui->ValeurReelX_2->setText(" " + afficheX); // Ecriture de la valeur X dans les "Coordonnées en Temps Réels"
    ui->ValeurReelY_2->setText(" " + afficheY); // Ecriture de la valeur Y dans les "Coordonnées en Temps Réels"
    ui->ValeurReelZ_2->setText(" " + afficheZ); // Ecriture de la valeur Z dans les "Coordonnées en Temps Réels"
    ui->Valeur_Reel_Vitesse->setText(" " + afficheV); // Ecriture de la valeur de la Vitesse dans les "Coordonnées en Temps Réels"

    float x = X;
    float y = Y;
    float z = Z;
    int v = V;
	data = new PilotageCharlyRobot(Coordonnee, CoordAbs, Texte, x, y, z, v, Trame, Lettre);
    data->launchmanu();
    envoietrame();



}
void CharlyRobot::ValiderOrigine()
{


    X = ui->DeplacementX_2->value(); // récupère la valeur manuelle de X
    Y = ui->DeplacementY_2->value(); // récupère la valeur manuelle de Y
    Z = ui->DeplacementZ_2->value(); // récupère la valeur manuelle de Z

    ui->Valeur_X_Origine->setText(" " + X);
    ui->Valeur_Y_Origine->setText(" " + Y);
    ui->Valeur_Z_Origine->setText(" " + Z);

    ui->Demarrer->setEnabled(true);
    float x = X;
    float y = Y;
    float z = Z;
    int v = V;
	data = new PilotageCharlyRobot(Coordonnee, CoordAbs, Texte, x, y, z, v, Trame, Lettre);
    data->recuppointrepere();
}

void CharlyRobot::view()
{
    Visuel visu;
    visu.setModal(true);
    visu.exec();


}

void CharlyRobot::OuvrirFichier()
{

    filename = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", "*.dxf");

    myfilter = new filtreDxf(Coordonnee, CoordAbs,Texte,filename,Lettre);
    myfilter->launch();
	popupstyle();
    ui->Demarrer->setEnabled(false);

	if (Lettre == true) {
		ui->l_police->setVisible(true);
		ui->c_police->setVisible(true);
		ui->b_police->setVisible(true);
	}
	else {
		ui->Demarrer->setEnabled(true);
		ui->l_police->setVisible(false);
		ui->c_police->setVisible(false);
		ui->b_police->setVisible(false);
	}
}

void CharlyRobot::ReglagePlaque()
{
    Reglage reglage;
    reglage.setModal(true);
    reglage.exec(); // Execution de la fenêtre de la classe "reglage"
}

void CharlyRobot::ReglageFraise()
{
    reglagefraise fraise;
    fraise.setModal(true);
    fraise.exec(); // Execution de la fenêtre de la classe "reglage"
}

void CharlyRobot::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawRect(50+160,10+240,10,50);

}

void CharlyRobot::AffichageTPSReel(int a)
{
	string str = Trame[a];
    string str2 = "@0M";
    int dfsd;
    size_t found = str.find(str2);
	if (found != string::npos)
	{
		int b = str.find(" ");
        int c = str.find(",", b + 1);
        string Valx = str.substr(b+1, c-(b+1));
        int d = str.find(",", c + 1);
        int e = str.find(",",d + 1);
        int f = str.find(",", e + 1);
        string Valy = str.substr(d + 1, e-(d+1));
        int g = str.find(",", f + 1);
        string Valz = str.substr(f+1,g-(f+1));

		QString X = QString::fromStdString(Valx);
		QString Y = QString::fromStdString(Valy);
		QString Z = QString::fromStdString(Valz);

		ui->ValeurReelX_2->setText(" " + X); // Ecriture de la valeur X dans les "Coordonnées en Temps Réels"
		ui->ValeurReelY_2->setText(" " + Y); // Ecriture de la valeur Y dans les "Coordonnées en Temps Réels"
		ui->ValeurReelZ_2->setText(" " + Z); // Ecriture de la valeur Z dans les "Coordonnées en Temps Réels"
    }
}

void CharlyRobot::effaceRAM()
{
	float x = X;
	float y = Y;
	float z = Z;
	int v = V;
	data = new PilotageCharlyRobot(Coordonnee, CoordAbs, Texte, x, y, z, v, Trame, Lettre);
	data->effRAM();
	envoietrame();
}

void CharlyRobot::popupstyle()
{
	//for (int i = 0; i < Texte.size(); i++) {
	//	if (Texte[i] == "NULL") {
	//		Texte[i] = "Arial";
	//		QMessageBox::critical(this, tr("Erreur"), tr("Cette police n'est pas prise en compte sur ce logiciel \n Veuillez utiliser les polices suivante :\n La police par defaut est ARIAL"), QMessageBox::Close);
	//		return;
	//	}
	//}
}

void CharlyRobot::recupstyle()
{
	QString val = ui->c_police->currentText();
	for (int i = 0; i < Texte.size(); i++) {
		if (Texte[i] == "Style") {
			Texte[i+1] = val.toStdString();
		}
	}
	ui->Demarrer->setEnabled(true);
}

void CharlyRobot::reset()
{
    float x = X;
    float y = Y;
    float z = Z;
    int v = V;
	data = new PilotageCharlyRobot(Coordonnee, CoordAbs, Texte, x, y, z, v, Trame, Lettre);
    data->reset();
    envoietrame();
}

void CharlyRobot::error()
{
	int ret = QMessageBox::critical(this, tr("Erreur"), tr("Coordonne X ou/et Y trop grand"), QMessageBox::Close);
}

CharlyRobot::~CharlyRobot()
{
    delete ui;
}



