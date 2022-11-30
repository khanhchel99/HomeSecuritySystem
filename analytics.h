#ifndef ANALYTICS_H
#define ANALYTICS_H


#ifndef __has_include
  static_assert(false, "__has_include not supported");
#else
#  if __cplusplus >= 201703L && __has_include(<filesystem>)
#    include <filesystem>
     namespace fs = std::filesystem;
#  elif __has_include(<experimental/filesystem>)
#    include <experimental/filesystem>
     namespace fs = std::experimental::filesystem;
#  elif __has_include(<boost/filesystem.hpp>)
#    include <boost/filesystem.hpp>
     namespace fs = boost::filesystem;
#  endif
#endif

#include <QDebug>
//#include <sqlite3.h>
#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
//#include <filesystem>
//#include <windows.h>
#include <array>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlQueryModel>

using namespace std;

using std::string;

class Analytics
{
public:

    static void Initialize();
    static void storeRecord(string starttime, string endtime, string description, string type);
    static std::array<std::array<string,10>, 10> RetrieveTable(string query);
    static string RetrieveSingle(string query);


private:

    Analytics();

    QSqlDatabase m_db;

    static Analytics* ptrInstance;
//    sqlite3* DB; // the pointer to the DB Handle, stored upon a successful database connection
    static Analytics& instance(){
        if(!ptrInstance){
            ptrInstance = new Analytics();
        }
        return *ptrInstance;
    }

    void privateInitialize();

    void privateStoreRecord(string starttime, string endtime, string description, string type);

    std::array<std::array<string,10>, 10> privateRetrieveTable(string query1);

    string privateRetrieveSingle(string query1);


};
#endif // ANALYTICS_H
