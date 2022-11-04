#include "controlpanel.h"
#include "./ui_controlpanel.h"
using namespace std;

QString defaultText = "Enter Passcode";
QString defaultStatusText = "Inactive";
QString falsePass = "Incorrect, try again";
int inputPass = 0;
bool activate = false;
int attemptCount = 0;
int timer;
bool power = 1;
bool alarmState = 0;
int truePassCode = 112345;
bool changecode = false;

ControlPanel::ControlPanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ControlPanel)
{
    ui->setupUi(this);

    //set default text on the display
    ui->Display->setText(defaultText);

    // set default text on status bar
    ui->Status->setText(defaultStatusText);

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
    connect(ui->Power, SIGNAL(released()), this, SLOT(KeyPressed()));
    connect(ui->stopAlarm, SIGNAL(released()), this, SLOT(KeyPressed()));
    connect(ui->ChangeCode, SIGNAL(released()), this, SLOT(KeyPressed()));
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
    if (QString::compare(keyVal, "activate", Qt::CaseInsensitive)==0){

        //put in verify password here
        if (inputPass == truePassCode){
           activate = true;
           ui->Display->setText("Success");
           ui->Status->setText("Active");
           attemptCount = 0;
        }else{

           ui->Display->setText(falsePass);
           attemptCount += 1;
           cout << attemptCount << endl;

           if (attemptCount == 3){

               ui->Display->setText("Wait 10 seconds");
               attemptCount = 0;
           }
        }
    }else if (QString::compare(keyVal, "deactivate", Qt::CaseInsensitive)==0){
        //put in verify password here
        if (inputPass == truePassCode){
           activate = false;
           ui->Display->setText("Success");
           ui->Status->setText("Inactive");
        }else{

           ui->Display->setText(falsePass);
           attemptCount += 1;
           cout << attemptCount << endl;

           if (attemptCount == 3){

               ui->Display->setText("Wait 10 seconds");
               attemptCount = 0;
           }
        }
    }
    else if (QString::compare(keyVal, "stopalarm", Qt::CaseInsensitive)==0){

        if (inputPass == truePassCode){

            alarmState = 0;

        }else{

           ui->Display->setText(falsePass);
           attemptCount += 1;
           cout << attemptCount << endl;

           if (attemptCount == 3){

               ui->Display->setText("Wait 10 seconds");
               attemptCount = 0;
           }
        }
    }
    else if (QString::compare(keyVal, "changecode", Qt::CaseInsensitive)==0){

        if(inputPass == truePassCode){

            inputPass = 0;
            changecode = true;

            ui->Display->setText("Enter New Code");
            ui->Display->repaint();

            if (QString::compare(keyVal, "changecode", Qt::CaseInsensitive)==0){

                if (inputPass != 0){
                    truePassCode = inputPass;
                    ui->Display->setText("New Passcode");
                }
                else{
                    ui->Display->setText("Passcode cant be 0");
                }
            }
        }
    }
    else if (QString::compare(keyVal, "power", Qt::CaseInsensitive)==0){

        ui->Display->setText("POWER OFF");
        power = 0;

    }


}

bool ControlPanel::getActiveStatus(){

    return activate;
}


bool ControlPanel::getPowerStatus(){

    return power;
}

void ControlPanel::activateAlarmState(){

    alarmState = 1;
    ui->Status->setText("ALARM");
}

bool getAlarmState(){

    return alarmState;
}




