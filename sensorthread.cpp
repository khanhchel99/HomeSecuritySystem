#include "sensorthread.h"
#include "homesystem.h"
#include <QtCore>
#include <iostream>
using namespace std;


sensorThread::sensorThread(QObject *parent) : QThread(parent)
{

}


void sensorThread::run(){
    while (1){
        if (homesystem::getSystemState()){
            if (exit){
                break;
            }
            if (sensor->getDisturbance()){
                homesystem::ringAlarm();
            }
            cout << "input from sensor" << endl;
            this->msleep(10);
        }else if (!homesystem::getSystemState()){
            cout << "system not activated" << endl;
            this->msleep(10);
        }

    }
}
