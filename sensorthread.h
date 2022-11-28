#ifndef SENSORTHREAD_H
#define SENSORTHREAD_H

#include <QThread>

class sensorThread : public QThread
{
    Q_OBJECT
public:
    explicit sensorThread(QObject *parent = 0);
    void run();
    bool exit = false;
};

#endif // SENSORTHREAD_H
