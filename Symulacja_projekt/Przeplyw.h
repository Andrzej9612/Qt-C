#ifndef PRZEPLYW_H
#define PRZEPLYW_H
#include <QGraphicsItem>
#include <QMainWindow>
#include <QPainter>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QtCore>
#include <QtGui>
class Przeplyw : public QWidget{
private:
    QColor kolor;
    double predkosc;
    int licznik;
    int opad;
    int x;
    int y;
    bool kierunek;
    bool start;
    char stan;//a-normalny, b-środkowy, c-skrajny
protected:
    void paintEvent(QPaintEvent *event);
public:
    Przeplyw(QWidget *parent, QColor kol, int x, int y, int opad, bool kier, bool s);
    void setPredkosc(double value);
    void przeplywanie();
    void setOpad(int value);
    void startuj();
    void setKolor(QColor kol);
    void setStan(char value);
    void reset(QColor kol, int x, int y, int opad, bool kier, bool s);
};

#endif // PRZEPLYW_H
