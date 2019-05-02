#include "filtreDxf.h"
#include <cmath>
#include "charlyrobot.h"
using namespace std;

/*L'organisation de la fonction se fera comme suit:
tout d'abord le type (point,Ligne, Cercle..) dans le vecteur Txt
ils iront a la place i de mon vecteur Txt a la meme place i dans le 
vecteur Coordonnées se trouve le nombre de Coordonées qui suivront 
dans le vecteur CAbs se trouve la valeur i de chaque nombre de coordonnée
et de chaque type de dessin
*/
//filtreDxf::filtreDxf() {
//
//}

filtreDxf::filtreDxf(std::vector<float>& Coordonnee, std::vector<int>& CoordAbs, std::vector<std::string>& Texte, QString path,bool& lettre)
	: C(Coordonnee), CAbs(CoordAbs), Txt(Texte), silettre(lettre)
{
	this->path = path.toStdString();
}
// la valeur data fait appel a la fonction dans le fichier dl_entities.h
void filtreDxf::addPoint(const DL_PointData & data)
{

	Txt.push_back("Point");
	int s = Txt.size();
	CAbs.push_back(s - 1);
	C.push_back(2);
	Txt.push_back("Point X");
	C.push_back(data.x);
	Txt.push_back("Point Y");
	C.push_back(data.y);
}


void filtreDxf::addMText(const DL_MTextData & data)
{
	string styles = data.style;
	int a = styles.find("standard");
	int b = styles.find("textstyle");
	string t;
	silettre = true;
	t = data.text;
	Txt.push_back("MText");
	CAbs.push_back(Txt.size() - 1);
	C.push_back(7);
	Txt.push_back(t);
	C.push_back(0);
	Txt.push_back("Style");
	C.push_back(0);
	if ((a != string::npos) || (b != string::npos)) {
		Txt.push_back("NULL");
		C.push_back(0);
	}
	else {
		Txt.push_back(data.style);
		C.push_back(0);
	}
	Txt.push_back("Mtext Hauteur");
	C.push_back(data.height);
	Txt.push_back("MText Largeur");
	C.push_back(data.width);
	Txt.push_back("Point InsX");
	C.push_back(data.ipx);
	Txt.push_back("Point InsY");
	C.push_back(data.ipy);

}

void filtreDxf::addEllipse(const DL_EllipseData& data) {
	float deg1, deg2;
	deg1 = data.angle1;
	deg2 = data.angle2;
	//transformation de radian en degrés
	deg1 = (180 * deg1) / M_PI;
	deg2 = (180 * deg2) / M_PI;
	Txt.push_back("Ellipse");
	C.push_back(7);
	Txt.push_back("Debut de l'angle en deg");
	C.push_back(deg1);
	Txt.push_back("Fin de l'angle en deg");
	C.push_back(deg2);
	Txt.push_back("Centre X");
	C.push_back(data.cx);
	Txt.push_back("Centre Y");
	C.push_back(data.cy);
	Txt.push_back("Coordonee en X du point final de l'axe principal");
	C.push_back(data.mx);
	Txt.push_back("Coordonee en Y du point final de l'axe principal");
	C.push_back(data.my);
	Txt.push_back("Ratio mineur/majeur");
	C.push_back(data.ratio);
}

void filtreDxf::addVertex(const DL_VertexData & data)
{
	Txt.push_back("Point X");
	C.push_back(data.x);
	Txt.push_back("Point Y");
	C.push_back(data.y);
}


void filtreDxf::addPolyline(const DL_PolylineData & data)
{
	cout << data.number << endl;
	Txt.push_back("Polyligne");
	CAbs.push_back(Txt.size() - 1);
	C.push_back(data.number*2);
}


void filtreDxf::launch()
{
	Txt.clear();
	CAbs.clear();
	C.clear();
	silettre = false;
	DL_Dxf dxf;
	if (dxf.in(path, this)) {
	}
}




void filtreDxf::addLine(const DL_LineData & data)
{
	Txt.push_back("Ligne");
	int s = Txt.size();
	CAbs.push_back(s - 1);
	C.push_back(4);
	Txt.push_back("Point X");
	C.push_back(data.x1);
	Txt.push_back("Point Y");
	C.push_back(data.y1);
	Txt.push_back("Point X");
	C.push_back(data.x2);
	Txt.push_back("Point Y");
	C.push_back(data.y2);
}

void filtreDxf::addArc(const DL_ArcData & data)
{
	Txt.push_back("Arc");
	int s = Txt.size();
	CAbs.push_back(s - 1);
	C.push_back(5);
	Txt.push_back("Centre X");
	C.push_back(data.cx);
	Txt.push_back("Centre Y");
	C.push_back(data.cy);
	Txt.push_back("Rayon");
	C.push_back(data.radius);
	Txt.push_back("Angle de Depart");
	C.push_back(data.angle1);
	Txt.push_back("Angle de fin");
	C.push_back(data.angle2);
}

void filtreDxf::addCircle(const DL_CircleData & data)
{
	string nom = "Cercle";
	Txt.push_back(nom);
	int s = Txt.size();
	CAbs.push_back(s - 1);
	C.push_back(3);
	Txt.push_back("Centre X");
	C.push_back(data.cx);
	Txt.push_back("Centre Y");
	C.push_back(data.cy);
	Txt.push_back("Rayon");
	C.push_back(data.radius);
}





filtreDxf::~filtreDxf()
{
	
}
