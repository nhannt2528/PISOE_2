
/*
READ_SPI -> PUSH_FIFO
READ LASTED FIFO -> REMOVE FIFO
*/
#ifndef TASK_SPI_H
#define TASK_SPI_H
#include <QtCore>
#include <QDebug>
#include <QThread>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <QTime>
#include <QDateTime>
#include <diCard.h>
#include <QObject>
#include <QQueue>
#define CHANNEL 0
#define SPEED 7000000
#define CS_1 24
#define CS_2 23
#define CS_3 22
#define CS_4 21
#define CS_5 20
#define LED 25
class task_spi :public QThread
{
public:
    task_spi();
    void run();
    dataCard getDequeue();
    int getCountFifo();
private:
    void spi_init();
    uint16_t spi_read(int cs,unsigned char num, dataCard &di) ;
    int m_toggleStatus;
      dataCard data[8];
      QQueue <dataCard> fifo;
signals:
void valueChanged(dataCard &data);

};
#endif
