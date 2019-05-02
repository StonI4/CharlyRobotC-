#pragma once
#include "dl_global.h"
#include "dl_dxf.h"
#include "dl_creationadapter.h"
#include <vector>
#include <string>
#include <QString>


/*Heritage (specialisation) de la classe DL_CreationAdapter*/
class filtreDxf : public DL_CreationAdapter{
private:
		
		
public: 
		std::string path;
		/*Mot clé virtual pour la specialisation des classe*/
		/*Ci dessous les classes publics expliquées dans le fichier Source.cpp*/
		virtual void addPoint(const DL_PointData& data);
		virtual void addLine(const DL_LineData& data);
		virtual void addArc(const DL_ArcData& data);
		virtual void addCircle(const DL_CircleData& data);
		virtual void addMText(const DL_MTextData& data);
		virtual void addEllipse(const DL_EllipseData& data);
		virtual void addVertex(const DL_VertexData& data);
		virtual void addPolyline(const DL_PolylineData& data);
		
		void launch();
		filtreDxf(std::vector<float>& Coordonnee,
			std::vector<int>& CoordAbs,
			std::vector<std::string>& Texte,
			QString path,bool &lettre);
		std::vector<float> &C;
		std::vector<int> &CAbs;
		std::vector<std::string> &Txt;
		bool &silettre;
	/*	filtreDxf();*/
		 


		

	~filtreDxf();
};


