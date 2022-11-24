#ifndef DICARD_H
#define DICARD_H
#include "qdatetime.h"
#include <cstdint>
struct dataCard
{
    uint16_t value;
    unsigned char offset;
    QDateTime time;

};
#endif // DICARD_H
