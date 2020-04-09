#ifndef WYKRESG_H
#define WYKRESG_H
#include <QGraphicsItem>
#include <QMainWindow>
#include <QtGui>
#include <deque>
using namespace std;
struct pair_i{
    int akt;
    int sp;
};

class WykresG : public QWidget{
private:
    int x;
    int y;
    int wysokosc;
    int szerokosc;
    double wartosc_max;
    double wartosc_min;
    int licznik;
    int pix_a;
    int pix_s;
    pair_i para;
     //1-H 2-T 0-brak
    deque<pair_i> historia_wartosciH;
    deque<pair_i> historia_wartosciT;
public:
    WykresG(QWidget *parent, int x, int y, int sz, int w, double min, double max);
    void zmianaHistori(double akt_h, double sp_h, double akt_T, double sp_T);
    void setMax(double max);
    void setMin(double min);
    void setWybor(int val);
    void czyscHistorieH();
    void czyscHistorieT();
    int wybor;
    void zerujLicznik();
protected:
    void paintEvent(QPaintEvent *event);

};
#endif // WYKRESG_H
