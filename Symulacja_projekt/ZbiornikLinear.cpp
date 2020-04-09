#include "ZbiornikLinear.h"
ZbiornikLinear::ZbiornikLinear()
{
    hot.flow = 22;
    hot.temp = 71;
    cold.flow = 34;
    cold.temp = 22;
    dis.flow = 15;
    dis.temp = 34;
    h_lin = 0;
    t_lin = 0;
}

void ZbiornikLinear::work()
{
    k1 = st*((-0.0112)*h_lin+0.0055*(hot.flow-Fh_pp+cold.flow-Fc_pp+dis.flow-Fd_pp));
    k2 = st*((-0.0112)*(h_lin+0.5*k1)+0.0055*((hot.flow-Fh_pp+cold.flow-Fc_pp+dis.flow-Fd_pp)+st/2));
    k3 = st*((-0.0112)*(h_lin+0.5*k2)+0.0055*((hot.flow-Fh_pp+cold.flow-Fc_pp+dis.flow-Fd_pp)+st/2));
    k4 = st*((-0.0112)*(h_lin+k3)+0.0055*((hot.flow-Fh_pp+cold.flow-Fc_pp+dis.flow-Fd_pp)+st));

    l1 = st*((-0.0669)*t_lin+0.0295*(hot.flow-Fh_pp)-0.0167*(cold.flow-Fc_pp)-0.0054*(dis.flow-Fd_pp));
    l2 = st*((-0.0669)*(t_lin+0.5*l1)+0.0295*((hot.flow-Fh_pp)+st/2)-0.0167*(cold.flow-Fc_pp+st/2)-0.0054*(dis.flow-Fd_pp+st/2));
    l3 = st*((-0.0669)*(t_lin+0.5*l2)+0.0295*((hot.flow-Fh_pp)+st/2)-0.0167*(cold.flow-Fc_pp+st/2)-0.0054*(dis.flow-Fd_pp+st/2));
    l4 = st*((-0.0669)*(t_lin+l3)+0.0295*((hot.flow-Fh_pp)+st)-0.0167*(cold.flow-Fc_pp+st)-0.0054*(dis.flow-Fd_pp+st));

    h_delta = (k1+2*k2+2*k3+k4)/6;

    t_delta = (l1+2*l2+2*l3+l4)/6;

h_lin = h_lin + h_delta;
t_lin = t_lin + t_delta;
h_akt = h_pp + h_lin;
t_akt = t_pp + t_lin;
}

double ZbiornikLinear::getHAkt()
{
    return h_akt;
}

double ZbiornikLinear::getTAkt()
{
    return t_akt;
}

double ZbiornikLinear::getFc()
{
    return cold.flow;
}

double ZbiornikLinear::getFh()
{
    return hot.flow;
}

double ZbiornikLinear::getFd()
{
    return dis.flow;
}

void ZbiornikLinear::setFlowHot(double value)
{
    hot.flow = value;
}

void ZbiornikLinear::setFlowCold(double value)
{
    cold.flow = value;
}

void ZbiornikLinear::setFlowDis(double value)
{
    dis.flow = value;
}

