#include "RegulatorLQR.h"
#include <QDebug>
RegulatorLQR::RegulatorLQR(double sph, double spt):
    sp_h(sph), sp_t(spt)
{
    ster_1 = 0;
    ster_2 = 0;
}

void RegulatorLQR::control(deque<double> histh, deque<double> histt)
{
 //   ster_1 = -0.2088*(histh.at(0)-sp_h) - 0.2068*(histt.at(0)-sp_t);
 //   ster_2 = -0.2144*(histh.at(0)-sp_h) + 0.1182*(histt.at(0)-sp_t);
    ster_1 = -0.0241*(histh.at(0)-sp_h) - 0.0219*(histt.at(0)-sp_t);
    ster_2 = -0.0242*(histh.at(0)-sp_h) + 0.0124*(histt.at(0)-sp_t);

}

void RegulatorLQR::setSpH(double value)
{
    sp_h = value;
}

double RegulatorLQR::getSpH()
{
    return sp_h;
}

void RegulatorLQR::setSpT(double value)
{
    sp_t = value;
}

double RegulatorLQR::getSpT()
{
    return sp_t;
}

double RegulatorLQR::getSter_1()
{
    return ster_1;
}

double RegulatorLQR::getSter_2()
{
    return ster_2;
}

