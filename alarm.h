#ifndef ALARM_H
#define ALARM_H

#include <iostream>
#include <iomanip>
//#include <sqlite3.h>
#include <string.h>
#include <chrono>
#include <sstream>
#include <vector>

#include <ctime>
//#include <wiringPi.h>


#endif

using namespace std;

class Alarm{

private:
    int alarmPin;
    time_t startID;
    time_t end;
    string description;
    bool alarmState;
    static Alarm* _instance;

    
    //prevent copying and assignment
    Alarm(const Alarm& other) = delete;
    Alarm& operator=(const Alarm& other) = delete;
    Alarm(string, int);
    static Alarm &instance() {
        if(_instance == NULL)
            _instance = new Alarm("LED alarm", 1);

        return *_instance;

    }

    void privateSetAlarm(time_t startID);
    void privateStopAlarm();
    bool privateCheckAlarmState();

public:

    static void setAlarm(time_t startID);
    static void stopAlarm();
    static bool checkAlarmState();

};
