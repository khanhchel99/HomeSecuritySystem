/*
    Author: Khanh Nguyen
    Description: Homesystem Singleton class that set,get state of alarm and system, ring or stop alarm
    Date: Nov 3, 2022
*/

#ifndef HOMESYSTEM_H
#define HOMESYSTEM_H

#include "sensorthread.h"

class homesystem
{
public:
    //public function to set system state
    static void setSystemState(bool sysState);
    //public function to get system state
    static bool getSystemState();
    //public function to set alarm state
    static void setAlarmState(bool alState);
    //public function to get alarm state
    static bool getAlarmState();
    //public function to ring alarm
    static void ringAlarm();
    //public function to stop the alarm
    static void stopAlarm();
    //delete the object
    static void Delete();
    //open control panel
    static void startUp(int argc, char *argv[]);

    sensorThread *sThread;

private:
    homesystem();

    static homesystem* ptrInstance;
    static homesystem& instance(){
        if(!ptrInstance){
            ptrInstance = new homesystem();
        }
        return *ptrInstance;
    }
    //ID of home
    //int homeID;
    bool systemState = false;
    bool alarmState =false;

    //private function to set system state
    void privateSetSystemState(bool privSysState);
    //private function to get system state
    bool privateGetSystemState();
    //private function to set alarm state
    void privateSetAlarmState(bool privAlState);
    //private function to get alarm state
    bool privateGetAlarmState();
    //private function to ring alarm
    void privateRingAlarm();
    //private function to stop alarm
    void privateStopAlarm();
    //private function to open control panel
    void privateStartUp(int argc, char *argv[]);
    //stop receiving input from sensor
    void privateStopSensor();
};

#endif // HOMESYSTEM_H
