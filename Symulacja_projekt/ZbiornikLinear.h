#ifndef ZBIORNIKLINEAR_H
#define ZBIORNIKLINEAR_H
#include "ZbiornikL.h"
class ZbiornikLinear{
private:
    pair hot;
    pair cold;
    pair dis;
    double h_akt;
    double t_akt;
    double h_delta;
    double t_delta;
    double h_lin;
    double t_lin;
    double k1,k2,k3,k4, l1, l2, l3, l4;
public:
    static constexpr double h_max = 30;
    static constexpr double t_min = 22;
    static constexpr double t_max = 71;
    static constexpr double Fc_pp = 34;
    static constexpr double Fd_pp = 15;
    static constexpr double Fh_pp = 22;
    static constexpr double h_pp = 17.44;
    static constexpr double t_pp = 39.72;
    static constexpr double st=1;
    ZbiornikLinear();
    void work();
    double getHAkt();
    double getTAkt();
    double getFc();
    double getFh();
    double getFd();
    void setFlowHot(double value);
    void setFlowCold(double value);
    void setFlowDis(double value);
};
#endif // ZBIORNIKLINEAR_H
