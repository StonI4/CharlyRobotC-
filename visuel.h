#ifndef VISUEL_H
#define VISUEL_H

#include <QDialog>

namespace Ui {
class Visuel;
}

class Visuel : public QDialog
{
    Q_OBJECT

public:
    explicit Visuel(QWidget *parent = 0);
    ~Visuel();
    virtual void paintEvent(QPaintEvent *event);

private:
    Ui::Visuel *ui;
};

#endif // VISUEL_H
