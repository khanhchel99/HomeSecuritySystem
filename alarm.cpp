#include <iostream>
#include <iomanip>
//#include <sqlite3.h>
#include <string.h>
#include <chrono>
#include <sstream>
#include <vector>

#include <ctime>

using namespace std;

class Alarm{

private:
    time_t startID;
    time_t end;
    string description;
    bool check;

public:

    Alarm(time_t ID, string descrip){

        startID = ID;
        description = descrip;
        time_t end;
        check = 1;
    }

    //setAlarm()

    void stopAlarm(time_t endTime){

        // stop physical alarm

        auto now = std::chrono::system_clock::now();
        end = std::chrono::system_clock::to_time_t(now);

        check = 0;

        // store in database
    }

    bool checkAlarm(){

        return check;
    }

};
