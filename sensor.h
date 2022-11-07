#ifndef SENSOR_H
#define SENSOR_H


class Sensor
{
private:
    //PhysicalSensor physicalSensor;
    bool disturbance;

public:
    Sensor();
    void setDisturbance(bool distChange);
    bool getDisturbance();
};

#endif // SENSOR_H
