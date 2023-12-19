#include "API.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    API w;
    w.show();
    return a.exec();
}
