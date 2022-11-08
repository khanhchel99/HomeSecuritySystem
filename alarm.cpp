#include <iostream>
using namespace std;
#include "alarm.h"

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
void alarm::Delete(){
    delete ptrInstance;
    ptrInstance = nullptr;
}
