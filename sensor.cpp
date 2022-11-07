#include "sensor.h"

Sensor::Sensor()
{
    disturbance = false;
    //physicalSensor = ...
}

void Sensor::setDisturbance(bool distChange){

    disturbance = distChange;
}

bool Sensor::getDisturbance(){

    return disturbance;
}
