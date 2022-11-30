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
    startID = "";
    description = "";
    
    // initialize physical alarm pins
    wiringPiSetup();
    pinMode(alarmPin, OUTPUT);

}


void alarm::privateSetAlarm(string descript){
    
    alarmState = true;
    digitalWrite(alarmPin, HIGH);
    cout << "Alarm ringing" + startID << endl;

    string TIMESTAMP; // initialize the variable for the incoming timestamp

    const auto now{chrono::system_clock::now()}; // get the present time and date
    const auto now_{chrono::system_clock::to_time_t(now)}; // convert the time and date to time_t format

    stringstream ss; // intialize a string stream to convert the timestamp into a string
    ss << put_time(localtime(&now_),"%a %b %d %H:%M:%S %Y"); //"%Y-%m-%d %H:%M:%S "); // convert the timestamp into a string
    TIMESTAMP = ss.str();

    startID = TIMESTAMP;
    description = descript;

    Analytics::storeRecord(startID, "", descript, "new");
    
}

void alarm::privateStopAlarm(){
    alarmState = false;
    digitalWrite(alarmPin, LOW);
    cout << "Alarm stopped" << endl;
    
    string TIMESTAMP; // initialize the variable for the incoming timestamp

    const auto now{chrono::system_clock::now()}; // get the present time and date
    const auto now_{chrono::system_clock::to_time_t(now)}; // convert the time and date to time_t format

    stringstream ss; // intialize a string stream to convert the timestamp into a string
    ss << put_time(localtime(&now_),"%a %b %d %H:%M:%S %Y"); //"%Y-%m-%d %I:%M:%S %p"); // convert the timestamp into a string
    TIMESTAMP = ss.str();

    if (startID != ""){
        Analytics::storeRecord(startID, TIMESTAMP, description, "stop");

        startID = "";
        description = "";
    }
    
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

