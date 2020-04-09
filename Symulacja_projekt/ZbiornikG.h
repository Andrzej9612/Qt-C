#ifndef ZBIORNIKG_H
#define ZBIORNIKG_H
#include <QGraphicsItem>
#include <QMainWindow>
#include <QPainter>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QtCore>
#include <QtGui>
#include "ZbiornikL.h"
#include "ZbiornikLinear.h"
#include "Przeplyw.h"
class ZbiornikG : public QWidget{
    Q_OBJECT
private:
    QTimer *timer;
    int x;
    int y;
    int h; //wysokość
    int Fi_dol; //średnica otworu na dole
    int Fi_gora; //średnica otworu na górze
    QColor color_temp;
    ZbiornikL *zbL;
    ZbiornikLinear *zbLin;
    Przeplyw *pc;
    Przeplyw *ph;
    Przeplyw *pd;

public:
  int wysokosc;
  Przeplyw *o;
public:
ZbiornikG(QWidget *parent = 0);
~ZbiornikG();
ZbiornikL* getZbL();
ZbiornikLinear* getZblin();
void start();
void stop();
void reset();
Przeplyw* getO();
protected:
void paintEvent(QPaintEvent *event);
public slots:
void odbior();
signals:
void ruch();
};
#endif // ZBIORNIKG_H
