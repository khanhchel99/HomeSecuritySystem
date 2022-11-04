#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QMainWindow>
#include <QTimer>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>
#include <iostream>

#include <chrono>
#include <thread>

QT_BEGIN_NAMESPACE
namespace Ui { class ControlPanel; }
QT_END_NAMESPACE

class ControlPanel : public QMainWindow
{
    Q_OBJECT

public:
    ControlPanel(QWidget *parent = nullptr);
    ~ControlPanel();
    bool getActiveStatus();
    bool getPowerStatus();
    void activateAlarmState();
    bool getAlarmState();

private:
    Ui::ControlPanel *ui;


//functions to be executed whenever a signal is submitted
private slots:
    //process whenever a number is pressed
    void NumPressed();
    //process whenever a activate/deactivate button is pressed
    void KeyPressed();

};


#endif // CONTROLPANEL_H
