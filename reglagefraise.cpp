#include "reglagefraise.h"
#include "ui_reglagefraise.h"

reglagefraise::reglagefraise(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reglagefraise)
{
    ui->setupUi(this);
    setWindowTitle ( "Réglage Fraise");
    LongeurFraise = ui->Valeur_Longeur_Fraise->value();
    EpaisseurFraise = ui->Valeur_Epaisseur_Fraise->value();

    connect(ui->Valider_Fraise,&QPushButton::clicked,this,&reglagefraise::Fermer);
}

void reglagefraise::Fermer()
{
    close();

}

reglagefraise::~reglagefraise()
{
    delete ui;
}
