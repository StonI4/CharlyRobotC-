#include "CharlyRobot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CharlyRobot w;
    w.show();

    return a.exec();
}
