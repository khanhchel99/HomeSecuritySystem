#ifndef SENSOR_H
#define SENSOR_H
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

class Sensor
{
private:
    int sensorPin;
    //PhysicalSensor physicalSensor;
    bool disturbance;
    
    static Sensor* _instance;
    
    //prevent copying and assignment
    Sensor(const Sensor& other) = delete;
    Sensor& operator=(const Sensor& other) = delete;
    Sensor();

public:
    
    static Sensor *instance();
    void setDisturbance(bool distChange);
    bool getDisturbance();
};

#endif // SENSOR_H
