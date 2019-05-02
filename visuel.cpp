#include "visuel.h"
#include "ui_visuel.h"
#include <QtCore>
#include <QtGui>

Visuel::Visuel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Visuel)
{
    ui->setupUi(this);
}

Visuel::~Visuel()
{
    delete ui;
}

void Visuel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);


    painter.drawLine(10,20,10,50);


}
