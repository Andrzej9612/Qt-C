#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ZbiornikG.h"
#include "SkalaH.h"
#include "Regulator.h"
#include "RegulatorLQR.h"
#include "Przeplyw.h"
#include <fstream>
#include "Kontrolka.h"
#include "WykresG.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void zbieranieDanych();
    
private:
    Ui::MainWindow *ui;
    ZbiornikG *zb;
    SkalaH *skalah;
    Regulator *rgt;
    Regulator *rgh;
    RegulatorLQR *rlqr;
    Kontrolka *konH;
    Kontrolka *konT;
    WykresG *wykres;
    int licznik;
    QString liniadanych;
    ofstream dane;
public slots:
    void odebranie();
private slots:
    void on_Fh_editingFinished();
    void on_Fc_editingFinished();
    void on_Fd_editingFinished();
    void on_pp_clicked();
    void on_sp_editingFinished();
    void on_spT_editingFinished();
    void on_start_clicked();
    void on_zbieranieD_clicked();
    void on_zbieranieD_K_clicked();
    void on_kp_editingFinished();
    void on_awaria_clicked();

    void on_tem_clicked();

    void on_wys_clicked();

    void on_ki_editingFinished();

    void on_kd_editingFinished();

    void on_stop_clicked();

signals:
    void klikStart();
};

#endif // MAINWINDOW_H
