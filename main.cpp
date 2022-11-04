#include "controlpanel.h"
#include "homesystem.cpp"
#include <QApplication>

#include <signal.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

//bool isInterrupted = false; // intialize the boolean variable indicating an interruption
//void signal_callback(int sign) {

//    cout << endl;
//    cout << "Ctrl + C entered, exiting."<< endl; // report that the the process is exiting

//    isInterrupted = true; // mark the application as interrupted
//}

int main(int argc, char *argv[])
{

    HomeSystem* syst = new HomeSystem(1, argc, argv);

//    signal(SIGINT, signal_callback);


    while(syst->getControlPanel()->getPowerStatus() == 1){

        // update the system status based on changes in the control panel

        if (syst->getControlPanel()->getActiveStatus() != syst->getSystemState()){

            syst->setSystemState(syst->getControlPanel()->getActiveStatus());
            cout << syst->getSystemState() << endl;
        }

        // if the system status is active, scan for sensor inputs

        if (syst->getSystemState() == true){

//            if (Sensor->state = true){

//                Alarm* alarm = syst->ringAlarm("Motion Sensor Triggered");

//                while(alarm->checkAlarm() == 1){

//                    if (syst->getControlPanel()->getAlarmState() == 0){

//                        auto now = std::chrono::system_clock::now();
//                        time_t ID = std::chrono::system_clock::to_time_t(now);

//                        syst->deactivateAlarmState();
//                        alarm->stopAlarm(ID);
//                    }
//                }

//            }

        }

//        cout << syst->getControlPanel()->getPowerStatus() << endl;
    }

    cout << "POWERED OFF" << endl;
    syst->getQApp()->closeAllWindows();

    delete syst;
    exit(0);
}
