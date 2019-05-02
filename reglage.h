#ifndef REGLAGE_H
#define REGLAGE_H

#include <QDialog>

namespace Ui {
class Reglage;
}

class Reglage : public QDialog
{
    Q_OBJECT

public:
    explicit Reglage(QWidget *parent = 0);
    ~Reglage();
    double EpaisseurPlak;
    double LongueurPlak;
    double LargeurPlak;
    void Fermer();


private:
    Ui::Reglage *ui;


};

#endif // REGLAGE_H
