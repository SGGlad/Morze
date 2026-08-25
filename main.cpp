#include "mainwindow.h"
#include <QApplication>
#include<QCoreApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    const QString dir = QCoreApplication::applicationDirPath();
    QCoreApplication::addLibraryPath(QDir(dir).absoluteFilePath("Sourse/plugins"));
    MainWindow w;
    w.show();
    return a.exec();
}
