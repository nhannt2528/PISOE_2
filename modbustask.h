#ifndef MODBUSTASK_H
#define MODBUSTASK_H
#include "modbustcp.h"
#include <QObject>
#include <diCard.h>
#define NUM_DI 8
class modbusTask : public QObject
{
    Q_OBJECT
public:
    explicit modbusTask(QObject *parent = nullptr);
void getData(HregDi &data);
private:
HregDi _temp_di;
modbusTCP *mbTCP;
uint16_t _value[NUM_DI];
uint16_t _m_value[NUM_DI];
struct dataHregDi
{
    bool value;
    int ID;
    QDateTime time;
    dataHregDi() {}
};
HregDi hregDi[NUM_DI*16];

void writeModbusInputStatus(HregDi &data);
void writeMobusHreg(HregDi &data);




signals:
void inputValueChanged();

};

#endif // MODBUSTASK_H
