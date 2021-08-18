#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <signal.h> // definitions of the interruptions signals (like kill() )

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

    QString standart_bash_command = "ps -auf ";
    QString filter_bash_arguments = "| head -1; ps -auf | grep ";

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
};
#endif // MAINWINDOW_H
