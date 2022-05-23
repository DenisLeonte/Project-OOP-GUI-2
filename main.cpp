#include "guiapp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUIApp w;
    w.show();
    return a.exec();
}
