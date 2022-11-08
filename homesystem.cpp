/*
    Author: Khanh Nguyen
    Description: Homesystem Singleton class that set,get state of alarm and system, ring or stop alarm
    Date: Nov 3, 2022
*/
#include <iostream>
using namespace std;
//
#include <QApplication>

#include "homesystem.h"
#include "controlpanel.h"
#include "alarm.h"

homesystem* homesystem::ptrInstance = nullptr;


homesystem::homesystem()
{

}
void homesystem::privateSetSystemState(bool privSysState){
    systemState = privSysState;
}
bool homesystem::privateGetSystemState(){
    return systemState;
}
void homesystem::privateSetAlarmState(bool privAlState){
    alarmState = privAlState;
}
bool homesystem::privateGetAlarmState(){
    return alarmState;
}
void homesystem::privateRingAlarm(){
    alarm::setAlarm("now");
}
void homesystem::privateStopAlarm(){
    alarm::stopAlarm();
}
//open control panel
void homesystem::privateStartUp(int argc, char *argv[]){
    QApplication a(argc, argv);
    ControlPanel w;
    w.show();
    a.exec();
}


void homesystem::setSystemState(bool sysState){
    instance().privateSetSystemState(sysState);
}
bool homesystem::getSystemState(){
    return instance().privateGetSystemState();
}
void homesystem::setAlarmState(bool alState){
    instance().privateSetAlarmState(alState);
}
bool homesystem::getAlarmState(){
    return instance().privateGetAlarmState();
}
void homesystem::ringAlarm(){
    instance().privateRingAlarm();
}
void homesystem::stopAlarm(){
    instance().privateStopAlarm();
}
void homesystem::Delete(){
    delete ptrInstance;
    ptrInstance = nullptr;
}
//
void homesystem::startUp(int argc, char *argv[]){
    instance().privateStartUp(argc, argv);
}
