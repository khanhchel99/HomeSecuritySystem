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
#include <wiringPi.h>

using namespace std;

class Alarm{

private:
    int alarmPin;
    //time_t startID;
    time_t end;
    string description;
    bool alarmState;
    static Alarm* _instance;
    
    //prevent copying and assignment
    Alarm(const Alarm& other) = delete;
    Alarm& operator=(const Alarm& other) = delete;
    Alarm(string, int);

public:

    static Alarm *instance();
    void setAlarm();
    void stopAlarm();
    bool checkAlarmState();

};

#endif
