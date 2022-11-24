#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    spi=new task_spi;
    time = new QDateTime;
    timeEdit = new QDateTimeEdit(QDateTime::currentDateTime());
    connect(timeEdit,&QTimeEdit::dateTimeChanged,this,&MainWindow::on_date_changed);
    QTimer *timer =new QTimer;
    //timer->setInterval();
    connect(timer,SIGNAL(timeout()),this,SLOT(task_update()));
    timer->start(1);
    spi.start(QThread::HighestPriority);
}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::on_date_changed(QDateTime time)
{


}
void MainWindow::task_update()
{
    if(spi.getCountFifo()>0){
 dataCard di =spi.getDequeue();
 modbusTask.getDataCard(di);
//qDebug()<<"get count"<<di.offset;
    }
}







