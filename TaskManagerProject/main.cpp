#include <cstdio>
#include <iostream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

#include <QString>

#include "mainwindow.h"

#include <QTableView>
#include <QApplication>

using namespace std;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
