#ifndef ALARM_H
#define ALARM_H
#include <ctime>
#include <string>
using namespace std;

class alarm
{
public:
    //public method to ring the alarm
    static void setAlarm(string startID);
    //public method to stop the alarm
    static void stopAlarm();
    //public method to get the current state of the alarm
    static bool checkAlarmState();
    //clean up
    static void Delete();

private:
    //constructor
    alarm(string descript, int pin);

    //static pointer to point to the alarm
    static alarm* ptrInstance;
    static alarm& instance(){
        //if there's no current alarm, create a new one
        if(!ptrInstance){
            ptrInstance = new alarm("LED alarm", 1);
        }
        return *ptrInstance;
    }

    //pin of the alarm
    int alarmPin;
    //startTime of the alarm
    string startID;
    string end;
    //description of the alarm
    string description;
    //state of the alarm
    bool alarmState;

    //private method to ring the alarm
    void privateSetAlarm(string startID);
    //private method to stop the alarm
    void privateStopAlarm();
    //private method to get the alarm state
    bool privateCheckAlarmState();

};

#endif // ALARM_H
