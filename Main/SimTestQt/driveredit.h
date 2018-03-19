#ifndef DRIVEREDIT_H
#define DRIVEREDIT_H

#include <QDialog>
#include "Modeling/Robot.h"
#include "Modeling/World.h"
#include "Simulation/WorldSimulation.h"


namespace Ui {
class DriverEdit;
}

class DriverEdit : public QDialog
{
    Q_OBJECT
    
public:
    explicit DriverEdit(RobotWorld* _world,WorldSimulation* _sim=NULL,QWidget *parent=0);
    ~DriverEdit();

    void SetRobot(Robot *robot_);
    void SetDriver(int _driver);
    void RequestSliderValues(int index);
    void addDrivers(vector<string> drivers);
    float min,max,value;
    void SendDriverValue();
    int current;
public slots:
    void NewSelection(int _current);
    void AddDriver(QString name);
    void RequestDriverParameters();
    void RequestDriverValue();
    void HandleSpinBox(double _value);
    void HandleSlider(int pos);
    void HandleKP(double value);
    void HandleKI(double value);
    void HandleKD(double value);
    void HandleDryFriction(double value);
    void HandleViscousFriction(double value);
    void HandleVmax(double value);
    void HandleAmax(double value);
    void HandleTmax(double value);
    void SaveSettings();
private:
    Ui::DriverEdit *ui;
    int driver;
    RobotWorld *world;
    WorldSimulation* sim;
    Robot* robot;
signals:
    void GetDriverValues(int i);
    void SetDriverValue(int index,float val);
};

#endif // DRIVEREDIT_H
