#include "Kontrolka.h"

Kontrolka::Kontrolka(QWidget *parent, int x, int y, double pg, double pd):
    QWidget(parent), x(x), y(y), prog_g(pg), prog_d(pd)
{
    setFixedSize(60, 60);
    setGeometry(x,y,60,60);
    czyMiga = false;
    predkosc = 10;
    licznik = 10;
}

void Kontrolka::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawEllipse(30,30,25,25);

    if(czyMiga==true){
        painter.setBrush(Qt::red);
        painter.drawEllipse(30,30,25,25);
    }
        painter.end();
}

void Kontrolka::migaj()
{
    if(licznik>=predkosc){
        if(czyMiga==true)czyMiga=false;
        else czyMiga=true;
        licznik = 0;
    }
    licznik++;
}

void Kontrolka::wylacz()
{
    czyMiga = false;
}

double Kontrolka::getProgG()
{
    return prog_g;
}

double Kontrolka::getProgD()
{
    return prog_d;
}

bool Kontrolka::getCzyMiga()
{
    return czyMiga;
}


