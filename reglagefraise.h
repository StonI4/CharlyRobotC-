#ifndef REGLAGEFRAISE_H
#define REGLAGEFRAISE_H

#include <QDialog>

namespace Ui {
class reglagefraise;
}

class reglagefraise : public QDialog
{
    Q_OBJECT

public:
    explicit reglagefraise(QWidget *parent = 0);
    ~reglagefraise();
    void Fermer();
    double LongeurFraise;
    double EpaisseurFraise;

private:
    Ui::reglagefraise *ui;
};

#endif // REGLAGEFRAISE_H
