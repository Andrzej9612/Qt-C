#ifndef SKALAH_H
#define SKALAH_H
#include <QGraphicsItem>
#include <QMainWindow>
#include <QtGui>
class SkalaH : public QWidget{
public:
    int x; //położenie x
    int y; //położenie y
    int H; //Wysokość osi
    double min; //wartość min na osi
    double max; //wartość max na osi
    static const int ilosc_przedzialow = 46;
    SkalaH(double min, double max, QWidget *parent);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // SKALAH_H
