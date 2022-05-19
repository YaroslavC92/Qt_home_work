#include "firstmyqtwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstMyQtWidget w;
    w.show();
    return a.exec();
}
