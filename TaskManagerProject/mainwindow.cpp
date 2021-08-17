#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <utils.h>

using namespace std;

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

QString MainWindow::get_filter_command(QString content2filter)
{
    return standart_bash_command + filter_bash_arguments + content2filter;
}

void MainWindow::set_proccesses_list(QString processes_list, bool filtered)
{

    ui->processes_plainTextEdit->setPlainText(processes_list);
    if(filtered) {
        filtered = true;
    }
}

QString MainWindow::get_standart_process_output()
{
    return standart_bash_command;
}

QString MainWindow::get_filtered_procces_output(QString command2execute)
{
    string command = command2execute.toStdString();
    string first_output = exec(command.c_str());
    QString output = QString::fromStdString(first_output);
    return output;
}

