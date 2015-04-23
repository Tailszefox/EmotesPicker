#include "actualpicker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ActualPicker w;
    w.show();

    return a.exec();
}
