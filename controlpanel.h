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


//functions to be executed whenever a signal is submitted
private slots:
    //process whenever a number is pressed
    void NumPressed();
    //process whenever a activate/deactivate button is pressed
    void KeyPressed();

};


#endif // CONTROLPANEL_H
