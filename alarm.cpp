#include "alarm.h"

Alarm* Alarm::_instance = NULL;


Alarm *Alarm::instance() {
    if(_instance == NULL)
        _instance = new Alarm("LED alarm", 1);

    return _instance;
    
}

Alarm::Alarm(string descrip, int pin){
        //startID = ID;
        description = descrip;
        alarmPin = pin;
        time_t end;
        alarmState  = false;
        alarmPin = 1;
        
        // initialize physical alarm pins
        wiringPiSetup();
        pinMode(alarmPin, OUTPUT);
}

void Alarm::setAlarm() {
    digitalWrite(alarmPin, HIGH);
    alarmState = true;
}

void Alarm::stopAlarm(){

    // stop physical alarm
    digitalWrite(alarmPin, LOW);

    auto now = std::chrono::system_clock::now();
    end = std::chrono::system_clock::to_time_t(now);

    alarmState = false;

    // store in database
}

bool Alarm::checkAlarmState(){
        return alarmState;
}
