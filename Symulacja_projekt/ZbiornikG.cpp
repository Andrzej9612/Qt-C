#include "ZbiornikG.h"
#include <QDebug>
ZbiornikG::ZbiornikG(QWidget *parent):
     QWidget(parent)
{
    setFixedSize(500, 800);
    setGeometry(30,50, 500,800);
    zbL = new ZbiornikL(17.44,39.72);
    zbLin = new ZbiornikLinear();
    h = 460;
    Fi_dol = 20;
    Fi_gora = 460;
    wysokosc = zbL->getHAkt()/30*h;
    int tmp = (zbL->getTAkt()-zbL->t_min)*255/(zbL->t_max - zbL->t_min);
    color_temp.setRgb(tmp, 0, 255-tmp);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(odbior()));
    ph = new Przeplyw(this, Qt::red, 130, 0, 200, true, false);
    pc = new Przeplyw(this, Qt::blue, 310, 0, 200, true, false);
    int tmp2 = (zbL->getDisTemp()-zbL->t_min)*255/(zbL->t_max - zbL->t_min);
    QColor disKolor;
    disKolor.setRgb(tmp2, 0, 255-tmp2);
    pd = new Przeplyw(this, disKolor, 220, 0, 200, true, false);
    o = new Przeplyw(this, color_temp, 230, 610, 200, false, false);

}

ZbiornikG::~ZbiornikG()
{
    timer->deleteLater();
    delete pd;
    delete zbL;
    delete zbLin;
    delete ph;
    delete pc;
    delete o;
}

ZbiornikL *ZbiornikG::getZbL()
{
    return zbL;
}

ZbiornikLinear *ZbiornikG::getZblin()
{
    return zbLin;
}

void ZbiornikG::start()
{
    timer->start(20);
}

void ZbiornikG::stop()
{
    timer->stop();
}

void ZbiornikG::reset()
{
    zbL->reset();
    wysokosc = zbL->getHAkt()/30*h;
    ph->reset(Qt::red, 130, 0, 200, true, false);
    pc->reset(Qt::blue, 310, 0, 200, true, false);
    ph->setStan('a');
    pc->setStan('a');
    int tmp2 = (zbL->getDisTemp()-zbL->t_min)*255/(zbL->t_max - zbL->t_min);
    QColor disKolor;
    disKolor.setRgb(tmp2, 0, 255-tmp2);
    int tmp = (zbL->getTAkt()-zbL->t_min)*255/(zbL->t_max - zbL->t_min);
    color_temp.setRgb(tmp, 0, 255-tmp);
    pd->reset(disKolor, 220, 0, 200, true, false);
    o->reset(color_temp, 230, 610, 200, false, false);
    this->repaint();
}

Przeplyw *ZbiornikG::getO()
{
    return o;
}

void ZbiornikG::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawLine(240,480+130,260,480+130);
    painter.drawLine(240,480+130,20,20+130);
    painter.drawLine(260,480+130, 480,20+130);
    double z = wysokosc*(Fi_gora-20)/(2*h);
    painter.drawLine(240-z,480-wysokosc+130, 260+z, 480-wysokosc+130);
    QPoint p1(240-z,480-wysokosc+130);
    QPoint p2(260+z,480-wysokosc+130);
    QPoint p3(260,480+130);
    QPoint p4(240,480+130);
    QVector<QPoint> vector;
    vector.push_back(p1);
    vector.push_back(p2);
    vector.push_back(p3);
    vector.push_back(p4);
    QPolygon polygon(vector);
    QPolygonF polygonf(polygon);
    QPainterPath patch;
    QBrush br(color_temp, Qt::SolidPattern);
    patch.addPolygon(polygonf);
    painter.fillPath(patch,br);
    painter.end();
}
void ZbiornikG::odbior(){
    zbL->work();
    zbLin->work();
   wysokosc=zbL->getHAkt()/30*h;
   ph->setOpad(480-wysokosc+130);
   ph->przeplywanie();
   pc->setOpad(480-wysokosc+130);
   pc->przeplywanie();
   pd->setOpad(480-wysokosc+130);
   pd->przeplywanie();
   o->przeplywanie();
   ph->setPredkosc(zbL->getFh());
   pc->setPredkosc(zbL->getFc());
   o->setPredkosc(zbL->getOdplyw());
   color_temp.setRgb((zbL->getTAkt()-zbL->t_min)*255/(zbL->t_max - zbL->t_min), 0, 255-(zbL->getTAkt()-zbL->t_min)*255/(zbL->t_max - zbL->t_min));
   o->setKolor(color_temp);
   if(90*460/220>wysokosc&&70*460/220<wysokosc) {ph->setStan('b');pc->setStan('b');}
   if(90*460/220>wysokosc&&70*460/220>wysokosc) {ph->setStan('c');pc->setStan('c'); }
   if(90*460/220<wysokosc&&70*460/220<wysokosc) {ph->setStan('a');pc->setStan('a'); }
   emit ruch();

}




