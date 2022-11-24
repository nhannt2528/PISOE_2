#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QDebug>
#include <QDateTime>
#include "QDateTime"
#include "QDateTimeEdit"
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include "task_spi.h"
#include "DI.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_date_changed(QDateTime time );

public slots:
void task_update();
private:
    Ui::MainWindow *ui;
    QDateTime *time;
    QDateTimeEdit *timeEdit;
    quint16 inputReg[8];
    task_spi spi;
    DI modbusTask;
signals:
    void valueIsChanged();
};
#endif // MAINWINDOW_H
