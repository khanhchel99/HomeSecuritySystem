#include "analytics.h"
#include <regex>

/*

QUERY IDEAS

most recent alarm: select starttime, endtime, description, (julianday(endtime) - julianday(starttime))*86400 as [duration] from AlarmRecords order by endtime desc LIMIT 1;

alarms last week: select count(*) from AlarmRecords where (julianday(endtime) - julianday(starttime)) < 8

alarms last month: select count(*) from AlarmRecords where (julianday(endtime) - julianday(starttime)) < 32

alarms last year: select count(*) from AlarmRecords where (julianday(endtime) - julianday(starttime)) < 366

5 recent: select starttime, endtime, description, (julianday(endtime) - julianday(starttime))*86400 as [duration] from AlarmRecords order by endtime desc LIMIT 5;

 *
 *
*/

Analytics* Analytics::ptrInstance = nullptr;

Analytics::Analytics(){
}

void Analytics::privateInitialize(){

    fs::path cwd = fs::current_path();
    string cwdpath = cwd.generic_string() + "/eyespy.db";
    cout << cwdpath << endl;

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(QString::fromStdString(cwdpath));

    if (!m_db.open())
       {
          qDebug() << "Error: connection with database failed";
       }
       else
       {
          qDebug() << "Database: connection ok";
       }

    QSqlQuery query;
    QString create("create table if not exists AlarmRecords (starttime DATETIME, endtime DATETIME, description varchar(255));");

    if(!query.exec(create)){
        qDebug() << "error executing statement: " << query.lastError().databaseText();
    }
}

void Analytics::privateStoreRecord(string starttime, string endtime, string description, string type){


    QSqlQuery query(m_db);

    QString Qstarttime = QString::fromStdString(starttime);
    QString Qendtime = QString::fromStdString(endtime);
    QString Qdesc = QString::fromStdString(description);


    if(type == "new"){

        query.prepare("insert into AlarmRecords (starttime, description) values (:stime, :desc)");
        query.bindValue(":stime",Qstarttime);
        query.bindValue(":etime",Qendtime);
        query.bindValue(":desc",Qdesc);
    }
    else if (type == "stop"){
        query.prepare("update AlarmRecords set endtime = :etime where starttime = :stime");
        query.bindValue(":stime",Qstarttime);
        query.bindValue(":etime",Qendtime);
        query.bindValue(":desc",Qdesc);
    }

    if(!query.exec())
    {
        qDebug() << "insert error:"
                 << query.lastError();
    }

}

std::array<std::array<string,10>, 10> Analytics::privateRetrieveTable(string query1){

//    cout << "retrieve query engaged" << endl;

    QSqlQuery query(m_db);

    query.prepare(QString::fromStdString(query1));

    if(!query.exec())
    {
        qDebug() << "select error:"
                 << query.lastError();
    }

//    cout << "query prepared" << endl;

    string starttime;
    string endtime;
    string description;

//    cout << "query size" + to_string(query.size()) << endl;

    static std::array<std::array<string,10>, 10> result;

    int startID = query.record().indexOf("starttime");
    int endID = query.record().indexOf("endtime");
    int descID = query.record().indexOf("description");

//    int index[10];
//    int fields_size = fields.size();


    int i = 0;
    while (query.next())

    {
//       cout << "i: " + to_string(i) << endl;
//       cout << "startID: " + to_string(startID) << endl;
       starttime = query.value(startID).toString().toStdString();
       endtime = query.value(endID).toString().toStdString();
       description = query.value(descID).toString().toStdString();

       string result_j;



           cout << "start time: " + starttime << endl;
           cout << "end time: " + endtime << endl;
           cout << "desc: " + description << endl;

       result[i][0] = starttime;
       result[i][1] = endtime;
       result[i][2] = description;

       i += 1;
       if (i==10){break;}

//           qDebug() << name;
    }



    return result;

}

string Analytics::privateRetrieveSingle(string query1){

    //    cout << "retrieve query engaged" << endl;

        QSqlQuery query(m_db);

        query.prepare(QString::fromStdString(query1));

        if(!query.exec())
        {
            qDebug() << "select error:"
                     << query.lastError();
        }

        if(!query.next()){
                qDebug() << query.lastError();
        }

        return query.value(0).toString().toStdString();

}

void Analytics::Initialize(){
    instance().privateInitialize();
}

void Analytics::storeRecord(string starttime, string endtime, string description, string type){
    instance().privateStoreRecord(starttime, endtime, description, type);
}

std::array<std::array<string,10>, 10> Analytics::RetrieveTable(string query){
    return instance().privateRetrieveTable(query);
}

string Analytics::RetrieveSingle(string query){
    return instance().privateRetrieveSingle(query);
}
