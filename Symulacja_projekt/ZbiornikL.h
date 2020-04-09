#ifndef ZBIORNIKL_H
#define ZBIORNIKL_H
#include <iostream>
#include <deque>

struct pair{
    double temp;
    double flow;
};
class ZbiornikL{
private:
    pair hot;
    pair cold;
    pair dis;
    double h_p;
    double t_p;
    double h_akt;
    double t_akt;
    double h_next;
    double t_next;
    std::deque<double> hist_h;
    std::deque<double> hist_t;
    int licznik;
    double odplyw;

public:
    static constexpr double h_max = 30;
    static constexpr double t_min = 22;
    static constexpr double t_max = 71;
    static constexpr double Fc_pp = 34;
    static constexpr double Fd_pp = 15;
    static constexpr double Fh_pp = 22;
    ZbiornikL(double h, double t);
    void work();
    double getHAkt();
    double getTAkt();
    double getFc();
    double getFh();
    double getFd();
    double getDisTemp();
    double getOdplyw();
    void setFlowHot(double value);
    void setFlowCold(double value);
    void setFlowDis(double value);
    void setRandomDis();
    std::deque<double> getHistH();
    std::deque<double> getHistT();
    void reset();
};




#endif // ZBIORNIKL_H
