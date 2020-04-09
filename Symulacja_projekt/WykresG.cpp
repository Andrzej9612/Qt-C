#include "WykresG.h"

WykresG::WykresG(QWidget *parent, int x, int y, int sz, int w, double min, double max):
    QWidget(parent), x(x), y(y), wysokosc(w), szerokosc(sz), wartosc_min(min), wartosc_max(max)
{
    setFixedSize(szerokosc, wysokosc);
    setGeometry(x,y,szerokosc, wysokosc);
    licznik = 0;
    pix_a = 0;
    pix_s = 0;
    wybor = 0;
}

void WykresG::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    QString str;
    painter.begin(this);
    painter.setBrush(Qt::white);
    painter.drawRect(0, 0, szerokosc-1, wysokosc-1);//okno
    painter.drawLine(60,wysokosc-30,szerokosc-30, wysokosc-30);//oś X
    painter.drawLine(60,wysokosc-30, 60, 20);//oś Y
    painter.drawLine(60, wysokosc-30, 50, wysokosc-30);//szara
    painter.drawPoint(100,100);
    for(int i=30; i<=300; i+=30){
        painter.setPen(Qt::gray);
        painter.drawLine(60, wysokosc-30-i, szerokosc-30, wysokosc-30-i);
        painter.setPen(Qt::black);
        painter.drawLine(50, wysokosc-30-i, 60, wysokosc-30-i);
        str = QString::number((wartosc_min+((wartosc_max-wartosc_min)/10)*(i/30-1)),  'f', 1);
        painter.drawText(7,wysokosc+5-i,str);
    }
    str = QString::number((wartosc_max),  'f', 1);
    painter.drawText(7,25,str);
    //painter.setBrush(Qt::white);
    painter.drawRect(szerokosc-151,0, 150, 75);
    deque<pair_i>::iterator it;
    int tmp = 0;
    if(wybor==1){
        painter.setPen(Qt::red);
        painter.drawLine(szerokosc-151+75, 25, szerokosc-151+130, 25);
        painter.setPen(Qt::blue);
        painter.drawLine(szerokosc-151+75, 50, szerokosc-151+130, 50);
        painter.setPen(Qt::black);
        painter.drawText(szerokosc-151+20,27,"h_akt");
        painter.drawText(szerokosc-151+20,52,"h_sp");
        for(it=historia_wartosciH.begin(); it!=historia_wartosciH.end(); it++){
            painter.setPen(Qt::red);
            painter.drawLine(tmp+60, (*it).akt-1, tmp+60, (*it).akt+1);
            painter.setPen(Qt::blue);
            if(((it+1)!=historia_wartosciH.end())&&(((*it).sp)!=((*(it+1)).sp))) painter.drawLine(tmp+60, (*it).sp-1, tmp+60, (*(it+1)).sp+1);
            painter.drawLine(tmp+60, (*it).sp-1, tmp+60, (*it).sp+1);
            tmp++;
        }
    }
    if(wybor==2){
        painter.setPen(Qt::red);
        painter.drawLine(szerokosc-151+75, 25, szerokosc-151+130, 25);
        painter.setPen(Qt::blue);
        painter.drawLine(szerokosc-151+75, 50, szerokosc-151+130, 50);
        painter.setPen(Qt::black);
        painter.drawText(szerokosc-151+20,27,"T_akt");
        painter.drawText(szerokosc-151+20,52,"T_sp");
        for(it=historia_wartosciT.begin(); it!=historia_wartosciT.end(); it++){
            painter.setPen(Qt::red);
            painter.drawLine(tmp+60, (*it).akt-1, tmp+60, (*it).akt+1);
            painter.setPen(Qt::blue);
            if(((it+1)!=historia_wartosciT.end())&&(((*it).sp)!=((*(it+1)).sp))) painter.drawLine(tmp+60, (*it).sp-1, tmp+60, (*(it+1)).sp+1);
            painter.drawLine(tmp+60, (*it).sp-1, tmp+60, (*it).sp+1);
            tmp++;
        }
    }
    painter.end();
}

void WykresG::zmianaHistori(double akt_h, double sp_h, double akt_T, double sp_T)
{
    if(wybor==1){
        pix_a = wysokosc-30-((akt_h-wartosc_min)*(300/(wartosc_max-wartosc_min)));
        pix_s = wysokosc-30-((sp_h-wartosc_min)*(300/(wartosc_max-wartosc_min)));
        para.akt = pix_a;
        para.sp = pix_s;
        if(licznik>=400){
            historia_wartosciH.pop_front();
            historia_wartosciH.push_back(para);
        }
        else{
        licznik++;
        historia_wartosciH.push_back(para);
        }
    }
    if(wybor==2){
        pix_a = wysokosc-30-((akt_T-wartosc_min)*(300/(wartosc_max-wartosc_min)));
        pix_s = wysokosc-30-((sp_T-wartosc_min)*(300/(wartosc_max-wartosc_min)));
        para.akt = pix_a;
        para.sp = pix_s;
        if(licznik>=400){
            historia_wartosciT.pop_front();
            historia_wartosciT.push_back(para);
        }
        else{
        licznik++;
        historia_wartosciT.push_back(para);
        }

    }
}

void WykresG::setMax(double max)
{
    wartosc_max = max;
}

void WykresG::setMin(double min)
{
    wartosc_min = min;
}

void WykresG::setWybor(int val)
{
    wybor = val;
}

void WykresG::czyscHistorieH()
{
    historia_wartosciH.clear();
}

void WykresG::czyscHistorieT()
{
    historia_wartosciT.clear();
}

void WykresG::zerujLicznik()
{
    licznik = 0;
}
