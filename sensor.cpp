#include "sensor.h"

Sensor* Sensor::_instance = NULL;


Sensor *Sensor::instance() {
    if(_instance == NULL)
        _instance = new Sensor();

    return _instance;
    
}

Sensor::Sensor()
{
    sensorPin = 0;
    disturbance = false;
    
    if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		exit(1);
	}
    
    pinMode(sensorPin,INPUT);
    //physicalSensor = ...
    
	
}

bool Sensor::getDisturbance(){
    return (digitalRead(sensorPin));
}
