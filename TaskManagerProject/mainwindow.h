#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <signal.h> // definitions of the interruptions signals (like kill() )
#include <sys/resource.h>
#include <sys/time.h>     // getpriority(int which, int who)  setpriority(int which, int who, int prio)
#include <sched.h>   // to allocate on a given CPU core

#include <QMainWindow>
#include <QTimer>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // methods for formating the command to print at screen
    QString get_standart_process_command();
    QString get_process_output(QString command2execute);

    QString standart_bash_command = "ps -eo user,pid,cpuid,%cpu,%mem,vsz,stat,start,time,pri,ni,command ";
    QString filter_bash_arguments = "| head -1; ps -eo user,pid,cpuid,%cpu,%mem,vsz,stat,start,time,pri,ni,command | grep ";

    bool filtered = false;
    void validate_filter();

    QString get_filter_command();
private:
    Ui::MainWindow *ui;
public slots:
    void set_processes_list();
private slots:
    void on_killPushButton_clicked();
    void on_stopPushButton_clicked();
    void on_continuePushButton_clicked();
    void on_setPriorityPushButton_clicked();
    void on_setCpuPushButton_clicked();
};
#endif // MAINWINDOW_H
