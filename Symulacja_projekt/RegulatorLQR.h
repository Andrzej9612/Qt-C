#ifndef REGULATORLQR_H
#define REGULATORLQR_H
#include <deque>
#include <iostream>
using namespace std;
class RegulatorLQR{
private:
    double sp_h;
    double sp_t;
    double ster_1;
    double ster_2;
public:
    RegulatorLQR(double sph, double spt);
    void control(deque<double> histh, deque<double> histt);
    void setSpH(double value);
    double getSpH();
    void setSpT(double value);
    double getSpT();
    double getSter_1();
    double getSter_2();
};
#endif // REGULATORLQR_H
