#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Facade facade;
    Controller controller(&facade);
    MainWindow w(&controller);
    w.show();
    return a.exec();
}
