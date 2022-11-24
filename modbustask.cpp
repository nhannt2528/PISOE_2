#include "modbustask.h"

modbusTask::modbusTask(QObject *parent)
    : QObject{parent}
{
    mbTCP =new modbusTCP;
    qDebug()<<"IP address is: " <<mbTCP->getLocalIp();
    mbTCP->setIP(mbTCP->getLocalIp());
    mbTCP->setPort(1025);
    mbTCP->setId(1);
    mbTCP->startConnection();
    mbTCP->addISts(0,256);
    mbTCP->addHreg(0,9000);
}
void modbusTask::getData(HregDi &data)
{
_temp_di=data;
writeModbusInputStatus(data);

}

void modbusTask::writeModbusInputStatus(HregDi &data)
{
for(int i=0;i<16;i++){
mbTCP->writeISts((data.offset*16)+i,data.value&(1<<i));
}
}



