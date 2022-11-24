#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QtCore>
#include <QDebug>

class myThread: public QThread
{
public:
    myThread();
    void run();
    QString _name;
};

#endif // MYTHREAD_H
