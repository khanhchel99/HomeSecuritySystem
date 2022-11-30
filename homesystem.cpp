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
#include "sensorthread.h"

homesystem* homesystem::ptrInstance = nullptr;


homesystem::homesystem()
{

}
void homesystem::privateSetSystemState(bool privSysState){
    systemState = privSysState;
  	if(!privSysState) {
		alarm::stopAlarm();
    }
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
    sThread = new sensorThread;
    sThread->start();
    a.exec();
}
void homesystem::privateStopSensor(){
    sThread = new sensorThread;
    sThread->exit = true;
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
	alarm::stopAlarm();
  	instance().privateSetSystemState(false);
	instance().privateStopSensor();
    delete ptrInstance;
    ptrInstance = nullptr;
    alarm::Delete();
}
//
void homesystem::startUp(int argc, char *argv[]){
    instance().privateStartUp(argc, argv);
}
