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

    // setting timer
    QTimer* process_timer = new QTimer(this);
    connect(process_timer, SIGNAL(timeout()), this, SLOT(set_processes_list()));
    process_timer->start(50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_processes_list()
{
    QString command;
    QString output;

    validate_filter();

    if(this->filtered) {
        command = this->get_filter_command();
    } else {
        command = this->get_standart_process_command();
    }

    // get the linux output of "ps -auf" with or without the filter
    output = this->get_process_output(command);
    // set it to the text box
    ui->processes_plainTextEdit->setPlainText(output);
}

QString MainWindow::get_filter_command()
{
    QString content2filter = ui->filter_lineEdit->text();
    return standart_bash_command + filter_bash_arguments + content2filter;
}

QString MainWindow::get_standart_process_command()
{
    return standart_bash_command;
}

QString MainWindow::get_process_output(QString command2execute)
{
    // function that makes the system call, and returns its output as a QString.
    string command = command2execute.toStdString();
    string first_output = exec(command.c_str());
    QString output = QString::fromStdString(first_output);
    return output;
}

void MainWindow::validate_filter()
{
    if(ui->filter_lineEdit->text().isEmpty())
    {
        this->filtered = false;
    }
    else
    {
        this->filtered = true;
    }
}




void MainWindow::on_killPushButton_clicked()
{
    if(!ui->PID_lineEdit->text().isEmpty()) {
        kill(ui->PID_lineEdit->text().toInt(), SIGKILL);
    }
}


void MainWindow::on_stopPushButton_clicked()
{
    if(!ui->PID_lineEdit->text().isEmpty()) {
        kill(ui->PID_lineEdit->text().toInt(), SIGSTOP);
    }
}


void MainWindow::on_continuePushButton_clicked()
{
    if(!ui->PID_lineEdit->text().isEmpty()) {
        kill(ui->PID_lineEdit->text().toInt(), SIGCONT);
    }
}


void MainWindow::on_setPriorityPushButton_clicked()
{
    if(!ui->PID_lineEdit->text().isEmpty() && !ui->setPriority_lineEdit->text().isEmpty()) {
        setpriority(PRIO_PROCESS, ui->PID_lineEdit->text().toInt(), ui->setPriority_lineEdit->text().toInt());
    }
}


void MainWindow::on_setCpuPushButton_clicked()
{
    if(!ui->PID_lineEdit->text().isEmpty() && !ui->setCpu_lineEdit->text().isEmpty()) {
        cpu_set_t  mask;
        CPU_ZERO(&mask);
        CPU_SET(ui->setCpu_lineEdit->text().toInt(), &mask);    // alocar na CPU 0

        sched_setaffinity(ui->PID_lineEdit->text().toInt(), sizeof(mask), &mask);
    }
}

