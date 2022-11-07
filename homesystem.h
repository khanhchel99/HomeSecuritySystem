#ifndef HOMESYSTEM_H
#define HOMESYSTEM_H


#include "controlpanel.h"
#include <QApplication>

#include <iostream>
#include <iomanip>
//#include <sqlite3.h>
#include <string.h>
#include <chrono>
#include <sstream>
#include <vector>

#include <QApplication>
#include "alarm.h"
#include "sensor.h"

#endif // HOMESYSTEM_H

class HomeSystem{

public:
    HomeSystem(int id, int argC, char *argV[]);
    ~HomeSystem();

    void activateSystem();
    void deactivateSystem();
    bool getSystemState();
    void setSystemState(bool state);
    ControlPanel* getControlPanel();
    QApplication* getQApp();
    Alarm* ringAlarm(string description);
    void deactivateAlarmState();
    Sensor* getSensor();

private:
    ControlPanel* controlPanel;
    int homeID;
    bool systemState;
    bool alarmState;
    QApplication* a;

    bool sensorState;
    Sensor* sensor;
};
