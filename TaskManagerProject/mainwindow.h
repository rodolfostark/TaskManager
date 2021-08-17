#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    QString get_standart_process_output();
    QString get_filtered_procces_output(QString command2execute);

    QString standart_bash_command = "ps -auf ";
    QString filter_bash_arguments = "| grep ";
    bool filtered = false;

    QString get_filter_command(QString content2filter);
private:
    Ui::MainWindow *ui;
public slots:
    void set_proccesses_list(QString processes_list, bool filtered);
};
#endif // MAINWINDOW_H
