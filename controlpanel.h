/*
    Author: Khanh Nguyen
    Description: UI for the control panel, process button pressed, check for password, etc.
    Date: Nov 3, 2022
*/
#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ControlPanel; }
QT_END_NAMESPACE

class ControlPanel : public QMainWindow
{
    Q_OBJECT

public:

    ControlPanel(QWidget *parent = nullptr);
    ~ControlPanel();

private:
    Ui::ControlPanel *ui;
    //password for the system
    QString password = "112345";
    //number of failed attempts
    int attemptCount = 0;
    QString defaultText = "Enter Passcode";
    QString falsePass = "Incorrect, try again";
    int inputPass = 0;
    //current state of home system
    bool activate = false;
    //allow passcode to be changed
    bool changeAllow = false;
    //current state of home system to be displayed
    QString currState = "System ";


//functions to be executed whenever a signal is submitted
private slots:
    //process whenever a number is pressed
    void NumPressed();
    //process whenever a activate/deactivate button is pressed
    void KeyPressed();

    void ChangePass();
};


#endif // CONTROLPANEL_H
