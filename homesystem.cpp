#include "homesystem.h"

using namespace std;


HomeSystem::HomeSystem(int id, int argC, char *argV[]){

    homeID = id;
    systemState = false;
    bool sensorState = false;
    bool alarmState = false;

    sensor = new Sensor();

    a = new QApplication(argC, argV);
    controlPanel =  new ControlPanel();
    controlPanel->show();
    a->exec();

}


HomeSystem::~HomeSystem(){
    a->closeAllWindows();
    delete controlPanel;

}

void HomeSystem::activateSystem(){
    systemState = true;

}

void HomeSystem::deactivateSystem(){
    systemState = false;
}

bool HomeSystem::getSystemState(){

    return systemState;
}

void HomeSystem::setSystemState(bool state){

    systemState = state;
}

ControlPanel* HomeSystem::getControlPanel(){

    return controlPanel;
}

QApplication* HomeSystem::getQApp(){

    return a;
}

Alarm* HomeSystem::ringAlarm(string description){

    auto now = std::chrono::system_clock::now();
    time_t ID = std::chrono::system_clock::to_time_t(now);

    alarmState = true;
    controlPanel->activateAlarmState();

    return new Alarm(ID, description);
}

void HomeSystem::deactivateAlarmState(){
    cout << "ALARM STATE DEACTIVATED" << endl;
    sensor->setDisturbance(false);

}

Sensor* HomeSystem::getSensor(){

    return sensor;
}








