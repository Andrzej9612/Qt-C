#include "Przeplyw.h"

void Przeplyw::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    if(kierunek==true){
        painter.begin(this);
        painter.drawLine(20,10,20,200);
        painter.drawLine(40,10,40,200);
        if(stan=='a') painter.fillRect(21,10,19,opad-10,kolor);
        if(stan=='c'){
            QPoint p1, p2, p3, p4;
            if(kolor==Qt::red){
                p1.setX(21);
                p1.setY(10);
                p2.setX(21);
                p2.setY(610-91*460/220);
                p3.setX(40);
                p3.setY(610-71*460/220);
                p4.setX(40);
                p4.setY(10);
            }
            if(kolor==Qt::blue){
                p1.setX(21);
                p1.setY(10);
                p2.setX(21);
                p2.setY(610-71*460/220);
                p3.setX(40);
                p3.setY(610-91*460/220);
                p4.setX(40);
                p4.setY(10);
            }
        QVector<QPoint> vector;
        vector.push_back(p1);
        vector.push_back(p2);
        vector.push_back(p3);
        vector.push_back(p4);
        QPolygon polygon(vector);
        QPolygonF polygonf(polygon);
        QPainterPath patch;
        QBrush br(kolor, Qt::SolidPattern);
        patch.addPolygon(polygonf);
        painter.fillPath(patch,br);
        }
        if(stan=='b'){
            QPoint p1, p2, p3, p4, p5;
            if(kolor==Qt::red){
                p1.setX(21);
                p1.setY(10);
                p2.setX(21);
                p2.setY(610-91*460/220);
                p3.setX(20+90-220*(610-opad)/460);
                p3.setY(opad);
                p4.setX(40);
                p4.setY(opad);
                p5.setX(40);
                p5.setY(10);
            }
            if(kolor==Qt::blue){
                p1.setX(21);
                p1.setY(10);
                p2.setX(21);
                p2.setY(opad);
                p3.setX(40-(90-220*(610-opad)/460));
                p3.setY(opad);
                p4.setX(40);
                p4.setY(610-91*460/220);
                p5.setX(40);
                p5.setY(10);
            }
            QVector<QPoint> vector;
            vector.push_back(p1);
            vector.push_back(p2);
            vector.push_back(p3);
            vector.push_back(p4);
            vector.push_back(p5);
            QPolygon polygon(vector);
            QPolygonF polygonf(polygon);
            QPainterPath patch;
            QBrush br(kolor, Qt::SolidPattern);
            patch.addPolygon(polygonf);
            painter.fillPath(patch,br);
        }
        painter.setPen(Qt::white);
        painter.drawLine(30,10+predkosc*licznik,30,25+predkosc*licznik);
        painter.drawLine(30,25+predkosc*licznik,27,22+predkosc*licznik);
        painter.drawLine(30,25+predkosc*licznik,33,22+predkosc*licznik);
        painter.end();
    }
    else{
        painter.begin(this);
        painter.drawLine(10,0,10,30);
        painter.drawLine(30,0,30,10);
        painter.drawLine(10,30,200,30);
        painter.drawLine(30,10,200,10);
        if(start==true){
            QPoint p1(10,0);
            QPoint p2(10,30);
            QPoint p3(200,30);
            QPoint p4(200,10);
            QPoint p5(30,10);
            QPoint p6(30,0);
            QVector<QPoint> vector;
            vector.push_back(p1);
            vector.push_back(p2);
            vector.push_back(p3);
            vector.push_back(p4);
            vector.push_back(p5);
            vector.push_back(p6);
            QPolygon polygon(vector);
            QPolygonF polygonf(polygon);
            QPainterPath patch;
            QBrush br(kolor, Qt::SolidPattern);
            patch.addPolygon(polygonf);
            painter.fillPath(patch,br);
            painter.setPen(Qt::white);
            painter.drawLine(15+predkosc*licznik,20,30+predkosc*licznik,20);
            painter.drawLine(30+predkosc*licznik,20,27+predkosc*licznik,23);
            painter.drawLine(30+predkosc*licznik,20,27+predkosc*licznik,17);
        }
        painter.end();
    }

}

Przeplyw::Przeplyw(QWidget *parent, QColor kol, int x, int y, int opad, bool kier, bool s):
    QWidget(parent), kolor(kol), x(x), y(y), opad(opad), kierunek(kier), start(s)
{  if(kierunek==true){
        setFixedSize(60, 500);
        setGeometry(x,y,60,200);
    }
   else{
        setFixedSize(220, 50);
        setGeometry(x,y,220,50);
    }
    licznik = 0;
    predkosc = 20;
    stan = 'a';

}

void Przeplyw::setPredkosc(double value)
{
    predkosc = value;
}

void Przeplyw::przeplywanie()
{
    if(licznik>(opad-40)/predkosc) licznik=0;
    licznik++;
}

void Przeplyw::setOpad(int value)
{
    opad = value;
}

void Przeplyw::startuj()
{
    start = true;
}

void Przeplyw::setKolor(QColor kol)
{
    kolor = kol;
}

void Przeplyw::setStan(char value)
{
    stan =value;
}

void Przeplyw::reset(QColor kol, int x, int y, int opad, bool kier, bool s)
{
    licznik = 0;
    predkosc = 20;
    kolor = kol;
    this->x = x;
    this->y = y;
    this->opad = opad;
    this->kierunek = kier;
    this->start = s;
}

