/*
    Author: Khanh Nguyen
    Description: Singleton class for homesystem
    Date: Nov 3, 2022
*/

#ifndef HOMESYSTEM_H
#define HOMESYSTEM_H



class homesystem
{
public:
    static void setSystemState(bool sysState);
    static bool getSystemState();
    static void setAlarmState(bool alState);
    static bool getAlarmState();
    static void ringAlarm();
    static void stopAlarm();
    static void Delete();
    //open control panel
    static void startUp(int argc, char *argv[]);

private:
    homesystem();

    static homesystem* ptrInstance;
    static homesystem& instance(){
        if(!ptrInstance){
            ptrInstance = new homesystem();
        }
        return *ptrInstance;
    }
    int homeID;
    bool systemState = false;
    bool alarmState =false;

    void privateSetSystemState(bool privSysState);
    bool privateGetSystemState();
    void privateSetAlarmState(bool privAlState);
    bool privateGetAlarmState();
    void privateRingAlarm();
    void privateStopAlarm();
    void privateStartUp(int argc, char *argv[]);
};

#endif // HOMESYSTEM_H
