#include <iostream>
#include <iomanip>
//#include <sqlite3.h>
#include <string.h>
#include <chrono>
#include <sstream>
#include <vector>

#include "controlpanel.h"
#include <QApplication>
#include "alarm.cpp"

using namespace std;

class HomeSystem{
private:
    ControlPanel* controlPanel;
    int homeID;
    bool systemState;
    bool alarmState;
    QApplication* a;

    bool sensorState;

public:

    HomeSystem(int id, int argC, char *argV[]){

        homeID = id;
        systemState = false;
        bool sensorState = false;
        bool alarmState = false;

        a = new QApplication(argC, argV);
        controlPanel =  new ControlPanel();
        controlPanel->show();
        a->exec();
    }


    ~HomeSystem(){
        a->closeAllWindows();
        delete controlPanel;

    }

    void activateSystem(){
        systemState = true;

    }

    void deactivateSystem(){
        systemState = false;
    }

    bool getSystemState(){

        return systemState;
    }

    void setSystemState(bool state){

        systemState = state;
    }

    ControlPanel* getControlPanel(){

        return controlPanel;
    }

    QApplication* getQApp(){

        return a;
    }

    Alarm* ringAlarm(string description){

        auto now = std::chrono::system_clock::now();
        time_t ID = std::chrono::system_clock::to_time_t(now);

        alarmState = true;
        controlPanel->activateAlarmState();

        return new Alarm(ID, description);
    }

    void deactivateAlarmState(){

        alarmState = false;
    }

    /*
    public void ringAlarm(){

    }
    */




};


