#include <iostream>
using namespace std;
#include "homesystem.h"

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
    cout << "Alarm goes off" << endl;
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

void homesystem::Deactivate(){
    delete ptrInstance;
    ptrInstance = nullptr;
}
