#include "alarm.h"

Alarm::Alarm(string descrip, int pin){
        description = descrip;
        alarmPin = pin;
        time_t end;
        alarmState  = false;
        alarmPin = 1;
        
        // initialize physical alarm pins
//        wiringPiSetup();
//        pinMode(alarmPin, OUTPUT);
}

void Alarm::privateSetAlarm(time_t ID) {
//    digitalWrite(alarmPin, HIGH);
    startID = ID;
    alarmState = true;
}

void Alarm::privateStopAlarm(){

    // stop physical alarm
//    digitalWrite(alarmPin, LOW);

    auto now = std::chrono::system_clock::now();
    end = std::chrono::system_clock::to_time_t(now);

    alarmState = false;

    // store in database
}

bool Alarm::privateCheckAlarmState(){
        return alarmState;
}

void Alarm::setAlarm(time_t ID){

    instance().privateSetAlarm(ID);
}

void Alarm::stopAlarm(){

    instance().privateStopAlarm();
}

bool Alarm::checkAlarmState(){

    instance().privateCheckAlarmState();
}
