#include "SkalaH.h"
#include <QDebug>
SkalaH::SkalaH(double min, double max, QWidget *parent):
    QWidget(parent), min(min), max(max)
{
    setFixedSize(50, 500);
    setGeometry(10,180, 50,500);
    H = 460;
}

void SkalaH::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    QString str;
    painter.begin(this);
    painter.drawLine(0,20,0,480);
    for(int i=0; i<=this->ilosc_przedzialow; i++){
    painter.drawLine(0,20+10*i,10,20+10*i);
    str = QString::number(max-((max-min)/this->ilosc_przedzialow*i),  'f', 1);
    painter.drawText(15,20+10*i+3,str);
    }
    painter.end();
}
