#include "sensorthread.h"
#include "homesystem.h"
#include <QtCore>
#include <iostream>
#include "notifyuser.h"

#include <chrono>

using namespace std;

sensorThread::sensorThread(QObject *parent) : QThread(parent) {

}


void sensorThread::run(){

    Sensor* sensor = Sensor::instance();
    NotifyUser notify;

    auto detection_start_time = std::chrono::steady_clock::now();
    auto current_time = std::chrono::steady_clock::now();

    bool sameDetection = false;

    while (1){
        if (homesystem::getSystemState()){
            if (exit){
                homesystem::stopAlarm();
                break;
            }
            if (sensor->getDisturbance()){
                homesystem::ringAlarm();

                if(!sameDetection) {
                    detection_start_time = std::chrono::steady_clock::now();
                    notify.emailUser("EyeSpy Home Security System has detected a disturbance. \nThe home alarm has been activated");
                    sameDetection = true;
                }

                current_time = std::chrono::steady_clock::now();
                
                if(std::chrono::duration_cast<std::chrono::seconds>(current_time - detection_start_time).count() > 10)
                    sameDetection = false;
                

/*                if(!emailSent) {
                    notify.emailUser("Alarm has been activated"); 
                    emailSent = true;
                } */
                
            }
            //cout << "input from sensor" << endl;
            this->msleep(10);
        }else if (!homesystem::getSystemState()){
            //cout << "system not activated" << endl;
            this->msleep(10);
        }

    }
}
