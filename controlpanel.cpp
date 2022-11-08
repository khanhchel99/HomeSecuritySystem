#include <iostream>
#include <cstdlib>
#include <vector>
#include <unistd.h>
#include "controlpanel.h"
#include "./ui_controlpanel.h"
#include "homesystem.h"
using namespace std;



ControlPanel::ControlPanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ControlPanel)
{
    ui->setupUi(this);

    //set default text on the display
    ui->Display->setText(defaultText);
    ui->CurrentState->setText(currState + "deactivated");

    //Assign numbers to its button
    QPushButton *numButs[10];
    for (int i=0;i <10; i++){
        QString numButtonName = "Button" + QString::number(i);
        //add the buttons to the button array
        numButs[i] = ControlPanel::findChild<QPushButton *>(numButtonName);
        //whenever the number button is pressed, execute function
        connect(numButs[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }

    connect(ui->Activate, SIGNAL(released()), this, SLOT(KeyPressed()));
    connect(ui->Deactivate, SIGNAL(released()), this, SLOT(KeyPressed()));
    connect(ui->ChangePass, SIGNAL(released()), this, SLOT(KeyPressed()));
    connect(ui->StopAlarm, SIGNAL(released()), this, SLOT(KeyPressed()));
    connect(ui->Ok, SIGNAL(released()), this, SLOT(ChangePass()));

}

ControlPanel::~ControlPanel()
{
    delete ui;
}

//process whenever a number is pressed
void ControlPanel::NumPressed(){
    QPushButton *numButton = (QPushButton *)sender();
    //get value of number from the button
    QString numVal = numButton->text();
    QString displayVal = ui->Display->text();

    //process when number is pressed
    if( (QString::compare(displayVal, defaultText, Qt::CaseInsensitive)==0) || (QString::compare(displayVal, falsePass, Qt::CaseInsensitive)==0) ){
        ui->Display->setText(numVal);
    }else {
        QString newDisplayVal = displayVal + numVal;
        int newPasscode = newDisplayVal.toInt();
        ui->Display->setText(QString::number(newPasscode));
    }
}

//process when activate or deactivate is pressed
void ControlPanel::KeyPressed(){
    QString displayVal = ui->Display->text();
    inputPass = displayVal.toInt();
    QPushButton *keyButton = (QPushButton *)sender();
    QString keyVal = keyButton->text();
    //when activate button is pressed
    if (QString::compare(keyVal, "activate", Qt::CaseInsensitive)==0){
        //put in verify password here
        if (inputPass == password.toInt()){
           activate = true;
           ui->CurrentState->setText(currState + "activated");
           ui->Display->setText("Success");
           attemptCount = 0;
           //set state of homesystem and alarm
           homesystem::setSystemState(true);
           homesystem::setAlarmState(true);
        }else{
           ui->Display->setText(falsePass);
           if(attemptCount<5){
               //increment 1 for every failed attempt
               attemptCount= attemptCount + 1;
           }else{
               //alert for exceeding number of failed attempts
               //call alertFunction in HomeSystem
               homesystem::ringAlarm();
               attemptCount = 0;
           }
        }
    //when deactivate button is pressed
    }else if (QString::compare(keyVal, "deactivate", Qt::CaseInsensitive)==0){
        //put in verify password here
        if (inputPass == password.toInt()){
           activate = false;
           ui->CurrentState->setText(currState + "deactivated");
           ui->Display->setText("Success");
           attemptCount = 0;
           //set state of homesystem and alarm
           homesystem::setSystemState(false);
           homesystem::setAlarmState(false);
        }else{
           ui->Display->setText(falsePass);
           if(attemptCount<4){
               //increment 1 for every failed attempt
               attemptCount= attemptCount + 1;
           }else{
               //alert for exceeding number of failed attempts
               //call alertFunction in HomeSystem
               homesystem::ringAlarm();
               attemptCount = 0;
           }
        }
    }else if (QString::compare(keyVal, "change pass", Qt::CaseInsensitive)==0){
        //put in verify password here
        if (inputPass == password.toInt()){
           ui->Display->setText("Please enter new 6 digits passcode");
           changeAllow = true;
           attemptCount = 0;
        }else{
           ui->Display->setText(falsePass);
           if(attemptCount<4){
               //increment 1 for every failed attempt
               attemptCount= attemptCount + 1;
           }else{
               //alert for exceeding number of failed attempts
               //call alertFunction in HomeSystem
               homesystem::ringAlarm();
               attemptCount = 0;
           }
        }
    }else if (QString::compare(keyVal, "stop alarm", Qt::CaseInsensitive)==0){
        //put in verify password here
        if (inputPass == password.toInt()){
           ui->Display->setText("Alarm Stopped");
           homesystem::stopAlarm();
        }else{
           ui->Display->setText(falsePass);
           if(attemptCount<4){
               //increment 1 for every failed attempt
               attemptCount= attemptCount + 1;
           }else{
               //alert for exceeding number of failed attempts
               //call alertFunction in HomeSystem
               homesystem::ringAlarm();
               attemptCount = 0;
           }
        }
    }

}

//process when OK button is clicked to change passcode
void ControlPanel::ChangePass(){
    if (changeAllow == true && ui->Display->text().length() == 6){
        password = ui->Display->text();
        ui->Display->setText("Passcode changed");
        changeAllow = false;
    }else if(changeAllow == false){
        ui->Display->setText("Enter passcode and click Change Pass");
    }else if (ui->Display->text().length() != 6){
        ui->Display->setText("6 digits only");
    }
}
