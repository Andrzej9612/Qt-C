#ifndef REGULATOR_H
#define REGULATOR_H
#include <deque>
#include <iostream>
using namespace std;
class Regulator{
private:
    double kp;
    double ki;
    double kd;
    double sp;
    double ster_1;
public:
    Regulator(double kp, double ki, double kd, double sp);
    void control(deque<double> hist);
    void setSp(double value);
    void setKp(double value);
    void setKi(double value);
    void setKd(double value);
    double getSp();
    double getKp();
    double getKi();
    double getKd();
    double getSter_1();
};

#endif // REGULATOR_H
