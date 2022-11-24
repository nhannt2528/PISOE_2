#include "task_spi.h"
task_spi::task_spi()
{

}
void task_spi::run()
{
    spi_init();
    while(1){
        spi_read(CS_1,0x00,data[0]);
        m_toggleStatus ^= 1;
        digitalWrite(LED, m_toggleStatus);
//        delay(1000);
    }
}
dataCard task_spi::getDequeue()
{
    return fifo.dequeue();
}
int task_spi::getCountFifo()
{
    return fifo.count();
}
void task_spi::spi_init()
{
    wiringPiSetup();
    pinMode(CS_1,OUTPUT);
    pinMode(CS_2,OUTPUT);
    pinMode(CS_3,OUTPUT);
    pinMode(LED,OUTPUT);
    digitalWrite(CS_1,HIGH);
    digitalWrite(CS_2,HIGH);
    digitalWrite(CS_3,HIGH);
    if( wiringPiSPISetupMode(0, SPEED,0)<0){
        qDebug()<<stderr<<"SPI SETUP FAILED! "<<strerror(errno);
    }
    else qDebug()<<"SPI init completed";
}
uint16_t task_spi::spi_read(int cs, unsigned char num,dataCard &di)
{
    static int i=0;
    i++;
    uint16_t data=0;
    unsigned char buf[2] = { 0xff,num};
    digitalWrite(cs,LOW);
    wiringPiSPIDataRW(0,buf,2);
    qDebug()<<buf[0]<<" "<<buf[1] ;
    data=buf[0];
    data=data<<8;
    data|=buf[1];
    digitalWrite(cs,HIGH);
       if(di.value!=data){
    di.offset=num;
    di.value=data;
    di.time=QDateTime::currentDateTime();
    emit valueChanged( di);
     }
    return data;
}
void task_spi::valueChanged(dataCard &data){
    fifo.append(data);
    qDebug()<<"fifo count: "<<fifo.count();
}


