#ifndef KONTROLKA_H
#define KONTROLKA_H
#include <QGraphicsItem>
#include <QMainWindow>
#include <QtGui>
class Kontrolka : public QWidget{
private:
    int x;
    int y;
    bool czyMiga;
    int predkosc;
    int licznik;
    double prog_g;
    double prog_d;
public:
    Kontrolka(QWidget *parent, int x, int y, double pg, double pd);
    void migaj();
    void wylacz();
    double getProgG();
    double getProgD();
    bool getCzyMiga();
protected:
    void paintEvent(QPaintEvent *event);

};
#endif // KONTROLKA_H
