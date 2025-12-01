#include "crcCalculate.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    crcCalculate w;
    w.show();
    w.setMinimumSize(QSize(800, 600));
    return a.exec();
}
