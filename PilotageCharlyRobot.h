#pragma once
#define MAX 1000
#include "dl_global.h"
#include "dl_dxf.h"
#include "dl_creationadapter.h"
#include <string>
#include <cstring>
#include <vector>


using namespace std;

class PilotageCharlyRobot{

public:
    /*PilotageCharlyRobot();*/
    void filtre();
    void conMillitoPm();
    void creationTramemanu();
    void creationTrame();
	void creationTrameMot();
    //int envoiTrame();
    void convfloattoint();
    void convdonnemanu();
    PilotageCharlyRobot(vector<float>&C,vector<int>&Cabs, vector<string>&T,float &CoordX, float &CoordY, float &CoordZ, int &VitesseV, vector<string>&trame,bool& lettre);
    ~PilotageCharlyRobot();
    vector<float>&Coordonnee;
    vector<string>&Texte;
	vector<int>&CoordonneeAbs;
	bool Clettre;
    void launch();
    void launchmanu();
    void reset();
    void recuppointrepere();
	void ajoutpointrepere();
	void ajoutHL();
	void convpointrepere();
	void verifdonne();
	void effRAM();
	void decalagedeslettres();
    float &Cx, &Cz, &Cy;
    int &Vv;
    vector<string>&Trame;
    int X, Y, Z;
	string TLC; //Corrige la derniere trame qui manque lors du traçage de la lettre (T=Trame,C=Correction,L=Lettre)
private:
	float repereX = 0.0, repereY = 0.0, repereZ = 0.0;
	int Rx, Ry, Rz;
    vector<float>donne;
	vector<int>donneconv;
	vector<int>donneAbs;

	int dgrandX = 0;
	int Hlettre = 0;
	int Llettre = 0;
	int px, py;
    vector<float>donneTxt;
	vector<int>donneTxtconv;
	vector<int>donneTxtABS;
	vector<int>nbpl; //Nombre de polyligne par lettre/Numero
	bool tramemot = false; //Change d'etat si il y a un Mtext
    int hz = 8900;
    //int hz = 9400;
    //vector<string>tramecopie;
	char min[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','k','t','s','t','u','v','x','y','z' };
	char maj[26] = { 'A','B','C','D','E','F','G','I','J','K','L','M','N','O','P','K','Q','R','S','T','U','V','W','X','Y','Z' };
	char num[10] = { '0','1','2','3','4','5','6','7','8','9' };
	string etat;
	string style;
	std::vector<float>plusgrandx;
	int nblettre=0;
};



