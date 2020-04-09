#include "ZbiornikL.h"
#include "cmath"
#include <QDebug>
#include <time.h>
ZbiornikL::ZbiornikL(double h, double t):
    h_akt(h), t_akt(t)
{
    hot.flow = 22;
    hot.temp = 71;
    cold.flow = 34;
    cold.temp = 22;
    dis.flow = 15;
    dis.temp = 34;
    h_next = 0;
    t_next = 0;
    licznik =0;
    srand (time(NULL));
}

void ZbiornikL::work()
{
    h_next = (hot.flow+cold.flow+dis.flow)/(0.6*h_akt*h_akt)-17/(0.6*pow(h_akt,1.5));
    t_next = (hot.flow*hot.temp+cold.flow*cold.temp+dis.flow*dis.temp-t_akt*(hot.flow+cold.flow+dis.flow))/(0.2*pow(h_akt, 3));
    if(licznik<=3){
        hist_h.push_front(h_akt);
        hist_t.push_front(t_akt);
    }
    else {
        licznik=5;
        hist_h.push_front(h_akt);
        hist_h.pop_back();
        hist_t.push_front(t_akt);
        hist_t.pop_back();
    }
    odplyw = 17*pow(h_akt,0.5);
    h_akt = h_akt+h_next;
    t_akt = t_akt+t_next;
    licznik++;
}

double ZbiornikL::getHAkt()
{
    return h_akt;
}

double ZbiornikL::getTAkt()
{
    return t_akt;
}

double ZbiornikL::getFc()
{
    return cold.flow;
}

double ZbiornikL::getFh()
{
    return hot.flow;
}

double ZbiornikL::getFd()
{
    return dis.flow;
}

double ZbiornikL::getDisTemp()
{
    return dis.temp;
}

double ZbiornikL::getOdplyw()
{
    return odplyw;
}

void ZbiornikL::setFlowHot(double value)
{
    hot.flow = value;
}

void ZbiornikL::setFlowCold(double value)
{
    cold.flow = value;
}

void ZbiornikL::setFlowDis(double value)
{
    dis.flow = value;
}

void ZbiornikL::setRandomDis()
{
    dis.flow = Fd_pp + (-100+rand()%200)/8;
}

std::deque<double> ZbiornikL::getHistH()
{
    return hist_h;
}


std::deque<double> ZbiornikL::getHistT()
{
    return hist_t;
}

void ZbiornikL::reset()
{
    h_akt = 17.44;
    t_akt = 39.72;
}
