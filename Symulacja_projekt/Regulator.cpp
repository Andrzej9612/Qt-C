
#include "Regulator.h"

Regulator::Regulator(double kp, double ki, double kd, double sp):
    kp(kp), ki(ki), kd(kd), sp(sp)
{

}
void Regulator::control(deque<double> hist)
{
    ster_1 = kp*(hist.at(0)-sp) + 0.5*ki*((hist.at(0)-sp)+(hist.at(1)-sp)+(hist.at(1)-sp)+(hist.at(2)-sp)+(hist.at(2)-sp)+(hist.at(3)-sp)) + kd*((hist.at(0)-sp)-(hist.at(1)-sp));
}

void Regulator::setSp(double value)
{
    sp = value;
}

void Regulator::setKp(double value)
{
    kp = value;
}

void Regulator::setKi(double value)
{
    ki = value;
}

void Regulator::setKd(double value)
{
    kd = value;
}

double Regulator::getSp()
{
    return sp;
}

double Regulator::getKi()
{
    return ki;
}

double Regulator::getKp()
{
    return kp;
}

double Regulator::getKd()
{
    return kd;
}

double Regulator::getSter_1()
{
    return ster_1;
}

