#include "reglage.h"
#include "ui_reglage.h"

Reglage::Reglage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reglage)
{

   ui->setupUi(this);
   setWindowTitle ( "Réglage Plaque");

   LargeurPlak = ui->Largeur_Plaque->value(); // Recupération de la valeur de "Largeur de la Plaque"
   LongueurPlak = ui->Longueur_Plaque->value();
   EpaisseurPlak = ui->Epaisseur_Plaque->value();

   connect(ui->Valider_Plaque,&QPushButton::clicked,this,&Reglage::Fermer);

}
void Reglage::Fermer()
{
    close();

}

Reglage::~Reglage()
{
    delete ui;
}

