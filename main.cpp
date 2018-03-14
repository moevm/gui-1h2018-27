#include "mainwindow.h"
#include <QApplication>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QMovie>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
