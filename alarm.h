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

#endif // ALARM_H

using namespace std;

class Alarm{

private:
    time_t startID;
    time_t end;
    string description;
    bool check;

public:

    Alarm(time_t ID, string descrip);
    void stopAlarm(time_t endTime);
    bool checkAlarm();

};
