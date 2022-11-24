#ifndef MULTITASK_H
#define MULTITASK_H
#include <QThread>
#include <QObject>

class MultiTask : public QObject,QThread
{
    Q_OBJECT
public:
    explicit MultiTask(QObject *parent = nullptr);

signals:

};

#endif // MULTITASK_H
