/*
    Author: Khanh Nguyen, Ian Guenther Green, Shubh Shah, Tabish Jabir
    Description: Alarm class that ring the alarm, stop alarm, get the state of the alarm
    Date: Nov 6, 2022
*/
#include <iostream>
using namespace std;
#include "alarm.h"

//allocate pointer
alarm* alarm::ptrInstance = nullptr;


alarm::alarm(string descript, int pin)
{
    description = descript;
    alarmPin = pin;

}


void alarm::privateSetAlarm(string startID){
    alarmState = true;
    cout << "Alarm ringing" + startID << endl;
}
void alarm::privateStopAlarm(){
    alarmState = false;
    cout << "Alarm stopped" << endl;
}
bool alarm::privateCheckAlarmState(){
    return alarmState;
}



void alarm::setAlarm(string startID){
    instance().privateSetAlarm(startID);
}
void alarm::stopAlarm(){
    instance().privateStopAlarm();
}
bool alarm::checkAlarmState(){
    return instance().privateCheckAlarmState();
}
//delete object
void alarm::Delete(){
    delete ptrInstance;
    ptrInstance = nullptr;
}
