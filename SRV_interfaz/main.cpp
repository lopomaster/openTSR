#include <QtGui/QApplication>
#include "mainwindow.h"
#include "QtGui"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setWindowIcon(QIcon(QString("logo.ico")));
    MainWindow w;
    w.showMaximized();

    try {
        return a.exec();
    }
        catch (...) {
        qDebug()<< "ERROR!";
    }
}
