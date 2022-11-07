#include "alarm.h"

using namespace std;

Alarm::Alarm(time_t ID, string descrip){

    startID = ID;
    description = descrip;
    time_t end;
    check = 1;
}

//setAlarm()

void Alarm::stopAlarm(time_t endTime){

    // stop physical alarm

    auto now = std::chrono::system_clock::now();
    end = std::chrono::system_clock::to_time_t(now);

    check = 0;

    // store in database INSERT

    // INSERT INTO [TABLE] VALUES(startID, end, description);
}

bool Alarm::checkAlarm(){

    return check;
}


