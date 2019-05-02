#include "PilotageCharlyRobot.h"
#include <vector>
#include <Windows.h>
#include <string>
#include <cstring>


using namespace std;
//***********************************************************************\\
//******************Recuperation de toutes les données utile*************\\
//***********************************************************************\\

PilotageCharlyRobot::PilotageCharlyRobot(vector<float>&C, vector<int>&Cabs, vector<string>&T, float &CoordX, float &CoordY, float &CoordZ, int &VitesseV, vector<string>&Trame,bool& lettre) : Coordonnee(C),CoordonneeAbs(Cabs), Texte(T), Cx(CoordX), Cy(CoordY), Cz(CoordZ), Vv(VitesseV), Trame(Trame), Clettre(lettre)
{
	//Recuperation de toutes les données utile au pilotage de charlyRobot
}


//***********************************************************************\\
//******************Gere le fichier DXF**********************************\\
//***********************************************************************\\

void PilotageCharlyRobot::filtre()
{
	string forme;
	int b = 0;
	plusgrandx.push_back(0);
	for (int a = 0; a < CoordonneeAbs.size(); a++) {
		forme = Texte[CoordonneeAbs[a]];

		if (forme == "Polyligne") {
			donneAbs.push_back(Coordonnee[CoordonneeAbs[a]]);
			for (b = CoordonneeAbs[a]; b <= (CoordonneeAbs[a] + Coordonnee[CoordonneeAbs[a]]); b++) {
				if (Texte[b] == "Point X") {
					donne.push_back(Coordonnee[b]);
				}
				if (Texte[b] == "Point Y") {
					donne.push_back(Coordonnee[b]);
				}
			}


		}
		if (forme == "Ligne") {
			donneAbs.push_back(Coordonnee[CoordonneeAbs[a]]);
			for (b = CoordonneeAbs[a]; b <= (CoordonneeAbs[a] + Coordonnee[CoordonneeAbs[a]]); b++) {
				if (Texte[b] == "Point X") {
					donne.push_back(Coordonnee[b]);
				}
				if (Texte[b] == "Point Y") {
					donne.push_back(Coordonnee[b]);
				}
			}
		}
		if (forme == "Cercle") {
			int x, y;
			float CX, CY, r;
			CX = Coordonnee[b + 1]; //Centre X
			CY = Coordonnee[b + 2]; //Centre Y
			r = Coordonnee[b + 3]; //Rayon
			b = b + 4;
			for (int t = 0; t < 360; t++) {
				x = CX + r * cos(t * M_PI / 180.0);
				y = CY + r * sin(t * M_PI / 180.0);
				donne.push_back(x);
				donne.push_back(y);
			}
			donneAbs.push_back(720);
		}
		if (forme == "MText") {
			tramemot = true;
			string text = Texte[a + 1];
			style = Texte[a + 3];
			Hlettre = Coordonnee[a + 4];
			Llettre = Coordonnee[a + 5];
			px = ((Coordonnee[a + 6] / 10) * 4000) / 8;
			py = ((Coordonnee[a + 7] / 10) * 4000) / 4;
			for (int i = 0; i < text.length(); ++i)
			{
				char lettre = text[i];
				for (int i = 0; i < 26; i++) {
					if (lettre == min[i]) {
						etat = "Minuscules";
						break;
					}
					if (lettre == maj[i]) {
						etat = "Majuscules";
						break;
					}
				}
				for (int i = 0; i < 9; i++) {
					if (lettre == num[i]) {
						etat = "Chiffres";
					}
				}

				string file = "D:\\" + style + "\\" + etat + "\\" + lettre + ".txt";
				ifstream monfichier(file, ios::in);
				if (monfichier) {
					string contenu;
					float grandx = 0.0;
					int nombredepolyligne = 0;
					while (getline(monfichier, contenu)) {
						if (contenu.find("Polyligne: ") != string::npos) {
							int k = contenu.find(": ");
							int l = contenu.length();
							string coordonnee = contenu.substr(k + 1, l);
							int c = stoi(coordonnee);
							donneTxtABS.push_back(c * 2);
							nombredepolyligne++;
						}
						if (contenu.find("Point X:") != string::npos) {
							int k = contenu.find(": ");
							int l = contenu.length();
							string coordonnee = contenu.substr(k + 1, l);
							float donne = stof(coordonnee);
							donne = plusgrandx[nblettre] + (donne*Llettre);
							donneTxt.push_back(donne);
							if (donne > grandx) {
								grandx = donne;
							}

						}
						if (contenu.find("Point Y:") != string::npos) {
							int k = contenu.find(": ");
							int l = contenu.length();
							string coordonnee = contenu.substr(k + 1, l);
							float donne = stof(coordonnee);
							donne = donne * Hlettre;
							donneTxt.push_back(donne);
						}
					}
					nblettre++;

					int tailleVecPGX = plusgrandx.size();
					if (tailleVecPGX == 1) {
						grandx = ((15 * Llettre) / 160) + grandx;
						plusgrandx.push_back(grandx);
					}
					else {
						grandx = grandx + plusgrandx[tailleVecPGX - 1];
						grandx = ((15 * Llettre) / 160)+ grandx;
						plusgrandx.push_back(grandx);
						
					}
					nbpl.push_back(nombredepolyligne); //Une lettre/chiffre peux etre composer de plusieurs polyligne 
				}
			}
		}
		if (forme == "Ellipse") {
			cout << "Marche" << endl;
		}
		if (forme == "Arc") {
			cout << "Marche" << endl;
		}
		if (forme == "Point") {
			cout << "Marche" << endl;
		}
	}



    //for (int a = 0; a < Texte.size(); a++) {
    //    if (Texte[a] == "Point X") {
    //        donne.push_back(Coordonnee[a]);
    //    }
    //    if (Texte[a] == "Point Y") {
    //        donne.push_back(Coordonnee[a]);
    //    }
    //    if (Texte[a] == "Nombre de polyligne") {
    //        NbSommet.push_back(Coordonnee[a]);
    //    }
    //}
}

void PilotageCharlyRobot::conMillitoPm()
{
    int w = 0;
    float var;
    for (int a = 0; a < donne.size(); a++) {
        if (w == 0) {
            donne[a] = ((donne[a] / 10) * 4000) / 8;
            w++;
        }
        else {
            donne[a] = ((donne[a] / 10) * 4000) / 4;
            w--;
        }
    }
	if (tramemot == true) {
		for (int a = 0; a < donneTxt.size(); a++) {
			if (w == 0) {
				donneTxt[a] = ((donneTxt[a] / 10) * 4000) / 8;
				w++;
			}
			else {
				donneTxt[a] = ((donneTxt[a] / 10) * 4000) / 4;
				w--;
			}
		}
	}
}

void PilotageCharlyRobot::convfloattoint()
{
	for (int z = 0; z < donne.size(); z++) {
		donneconv.push_back(donne[z]);
	}
	if (tramemot == true) {
		for (int z = 0; z < donneTxt.size(); z++) {
			donneTxtconv.push_back(donneTxt[z]);
		}
	}
}

void PilotageCharlyRobot::ajoutHL()
{
	//Hlettre = ((Hlettre / 10) * 4000) / 8;
	//Llettre = ((Llettre / 10) * 4000) / 8;
	int w = 0;
	for (int a = 0; a < donneTxt.size(); a++) {
		if (w == 0) {
			donneTxt[a] = donneTxt[a] * Hlettre;
			w++;
		}
		else {
			donneTxt[a] = donneTxt[a] * Llettre;
			w--;
		}
	}
}

void PilotageCharlyRobot::decalagedeslettres()
{
	if (tramemot == true) {
		/*int nb = 0;
		int b = 0;


		int saveposition = 0;
		for (int a = 0; a < nbpl.size(); a++) {
			for (int i = 0; i < donneTxt.size(); i++) {
				for (int c = 0; c < donneTxtABS[b]; c++) {
					if (ww == 0) {
						donneTxt[i] = donneTxt[i] + decalage;
						ww++;
					}
					else {
						ww--;
					}
				}

			}
			for (b; b < (nbpl[a] + saveposition); b++) {
				for (int c = 0; c < donneTxtABS[b]; c++) {
					if (w == 0) {
						if (donneTxt[c] > dgrandX) {
							dgrandX = donneTxt[c];
							decalage = dgrandX + (15 * Hlettre) / 160;
						}
						w++;
					}
					else {
						w--;
					}
				}
			}
			saveposition = saveposition + b;
		}
	}*/
	//	for (int i = 0; i<plusgrandx.size(); i++) {
	//		plusgrandx[i] = plusgrandx[i] + (15 * Llettre / 160);
	//	}
	//	int decalage = 0;
	//	int saveposition = 0; //Suivie des polylignes
	//	int y = 0; //Suivie des donnees
	//	int w = 0;
	//	int ww = 0;
	//	for (int a = 0; a < nbpl.size(); a++) {
	//		for (int b = 0; b < nbpl[a]; b++) {
	//			for (b; b < (nbpl[a] + saveposition); b++) {
	//				for (int c = 0; c < donneTxtABS[b]; c = c + 2) {

	//					nb = nb + 2;
	//				}
	//			}
	//			saveposition = saveposition + b;
	//		}
	//		for (int d = 0; d < donneTxt.size(); d++) {
	//			if (ww == 0) {
	//				donneTxt[d] = donneTxt[d] + decalage;
	//				ww++;
	//			}
	//			else {
	//				ww--;
	//			}
	//		}
	//		decalage = 0;
	//	}
	}
}


//***********************************************************************\\
//******************Deplacement manuel***********************************\\
//***********************************************************************\\

void PilotageCharlyRobot::convdonnemanu()
{
    //Conversion mm en pas moteur
    Cx = ((Cx / 10) * 4000) / 8;
    Cy = ((Cy / 10) * 4000) / 4;
    Cz = ((Cz / 10) * 4000) / 4;
    //Conversion float en int
    X = Cx;
    Y = Cy;
    Z = Cz;
}

void PilotageCharlyRobot::creationTramemanu()
{
	Trame.clear();
	//On créer la Trame créer manuellement
	Trame.push_back("@07\r");
	Trame.push_back(string("@0M ") + to_string(X) + string(",") + to_string(Vv) + string(",") + to_string(Y) + string(",") + to_string(Vv) + string(",") + to_string(Z) + string(",") + to_string(Vv) + string(",") + "0,100\r");
	Trame.push_back("9\r");

}

//***********************************************************************\\
//******************Creation de la trame*********************************\\
//***********************************************************************\\

void PilotageCharlyRobot::creationTrame()
{
	Trame.clear();
	Trame.push_back("@07\r");
	Trame.push_back("@0R7\r");
	int nb = 0;
	if (tramemot == true) {
		creationTrameMot();
	}
	for (int a = 0; a < donneAbs.size(); a++) {
		for (int c = 0; c < donneAbs[a]; c=c+2) {
			Trame.push_back(string("@0M ") + to_string(donneconv[nb]) + string(",1800,") + to_string(donneconv[nb + 1]) + string(",1800,") + to_string(hz) + ",1800,0,100\r");
			nb = nb + 2;
		}
		int releve = hz - (hz * 0.05);

		Trame.push_back(string("@0M ") + to_string(donneconv[nb - 2]) + string(",1800,") + to_string(donneconv[nb - 1]) + string(",1800,")+to_string(releve) + ",1800,0,100\r");
	}
	Trame.push_back("@0R7\r");
	Trame.push_back("9\r");
}

void PilotageCharlyRobot::creationTrameMot()
{
	int nb = 0;
	int b = 0;
	int saveposition = 0;
	for (int a = 0; a < nbpl.size(); a++) {
		for (b; b < (nbpl[a]+saveposition); b++) {
			for (int c = 0; c < donneTxtABS[b]; c=c+2) {
				Trame.push_back(string("@0M ") + to_string(donneTxtconv[nb]) + string(",1800,") + to_string(donneTxtconv[nb + 1]) + string(",1800,") + to_string(hz) + ",1800,0,100\r");
				nb = nb + 2;
			}
			int releve = hz - (hz * 0.05);

			Trame.push_back(string("@0M ") + to_string(donneTxtconv[nb - 2]) + string(",1800,") + to_string(donneTxtconv[nb - 1]) + string(",1800,") + to_string(releve) + ",1800,0,100\r");
		}
		saveposition = saveposition + b;
	}
}

//***********************************************************************\\
//******************Lancement de programme*******************************\\
//***********************************************************************\\

void PilotageCharlyRobot::launch()
{
    filtre();
	if (tramemot == true) {
		//ajoutHL();
		decalagedeslettres();
	}
	conMillitoPm();
	convfloattoint();
	//decalagedeslettres();
	//ajoutpointrepere();
	verifdonne();
    creationTrame();
}

void PilotageCharlyRobot::launchmanu()
{
    convdonnemanu();
    creationTramemanu();
}

//***********************************************************************\\
//******************remise a zero****************************************\\
//***********************************************************************\\

void PilotageCharlyRobot::reset()
{
    Trame.clear();
    Trame.push_back("@07\r");
    Trame.push_back("@0R7\r");
    Trame.push_back("9\r");
}


//***********************************************************************\\
//******************Point de repere**************************************\\
//***********************************************************************\\

void PilotageCharlyRobot::recuppointrepere()
{
	repereX = Cx;
	repereY = Cy;
	repereZ = Cz;
	convpointrepere();
}

void PilotageCharlyRobot::convpointrepere()
{
	//Conversion mm en pas moteur
	repereX = ((repereX / 10) * 4000) / 8;
	repereY = ((repereY / 10) * 4000) / 4;
	repereZ = ((repereZ / 10) * 4000) / 4;
	//Conversion float en int
	Rx = repereX;
	Ry = repereY;
	Rz = repereY;
}

void PilotageCharlyRobot::ajoutpointrepere()
{
	int w = 0;
	float var;
	for (int a = 0; a < donneconv.size(); a++) {
		if (w == 0) {
			donneconv[a] = donneconv[a] + Rx;
			w++;
		}
		else {
			donneconv[a] = donneconv[a] + Ry;
			w--;
		}
	}
	if (tramemot == true) {
		for (int a = 0; a < donneTxtconv.size(); a++) {
			if (w == 0) {
				donneTxtconv[a] = donneTxtconv[a] + Rx;
				w++;
			}
			else {
				donneTxtconv[a] = donneTxtconv[a] + Ry;
				w--;
			}
		}
	}
}



//***********************************************************************\\
//******************Verification des donnees*****************************\\
//***********************************************************************\\

void PilotageCharlyRobot::verifdonne()
{
	int w = 0;
	float var;
	for (int a = 0; a < donneconv.size(); a++) {
		if (w == 0) {
			if(donneconv[a] > 14000){
				EXIT_FAILURE;
			}
			w++;
		}
		else {
			if (donneconv[a] > 16000) {
				EXIT_FAILURE;
			}
			w--;
		}
	}
	if (tramemot == true) {
		for (int a = 0; a < donneTxtconv.size(); a++) {
			if (w == 0) {
				if (donneTxtconv[a] > 14000) {
					EXIT_FAILURE;
				}
				w++;
			}
			else {
				if (donneTxtconv[a] > 16000) {
					EXIT_FAILURE;
				}
				w--;
			}
		}
	}
}

void PilotageCharlyRobot::effRAM()
{
	Trame.clear();
	Trame.push_back("@07\r");
	Trame.push_back("@0k\r");
	Trame.push_back("9\r");
}



//***********************************************************************\\
//******************Chercher les fichiers...*****************************\\
//***********************************************************************\\





PilotageCharlyRobot::~PilotageCharlyRobot()
{
}
/*
trace 1°L
 
 for(int i=0;i<nblettre;i++){
	coordonnéé = plusgrandx+coordonnee;
 }


*/
