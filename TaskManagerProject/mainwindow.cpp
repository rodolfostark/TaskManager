#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <utils.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // captures the output of processes linux command
    string saida = exec("ps -auf");
    ui->processes_plainTextEdit->setPlainText(QString::fromStdString(saida));
}

MainWindow::~MainWindow()
{
    delete ui;
}

