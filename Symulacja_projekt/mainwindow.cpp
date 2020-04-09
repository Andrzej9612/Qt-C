#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBoxLayout>
#include <QDebug>
#include <QDate>
#include <QTime>
#include <string>
#include <QFileDialog>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zb = new ZbiornikG(this);
    licznik = 0;
    skalah = new SkalaH(0, 30, this);
    konH = new Kontrolka(this,1080,175, 25.0, 10.0);
    konT = new Kontrolka(this,1080,215, 65.0, 30.0);
    wykres = new WykresG(this,550, 300, 750, 350, 0, 30);
    connect(zb, SIGNAL(ruch()), this, SLOT(odebranie()));
    rgh = new Regulator(0.05,0.02,2,17.44);
    rgt = new Regulator(0.02,0.01,1,39.72);
    rlqr = new RegulatorLQR(13,45);
    ui->kp->setValue(rgh->getKp());
    ui->ki->setValue(rgh->getKi());
    ui->kd->setValue(rgh->getKd());
    ui->sp->setValue(rgh->getSp());
    ui->kp->editingFinished();
    ui->ki->editingFinished();
    ui->kd->editingFinished();
    ui->sp->editingFinished();
    ui->kpT->setValue(rgt->getKp());
    ui->kiT->setValue(rgt->getKi());
    ui->kdT->setValue(rgt->getKd());
    ui->spT->setValue(rgt->getSp());
    ui->kpT->editingFinished();
    ui->kiT->editingFinished();
    ui->kdT->editingFinished();
    ui->spT->editingFinished();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::zbieranieDanych()
{
   liniadanych = QString::number(zb->getZbL()->getHAkt())+";"+QString::number(zb->getZbL()->getTAkt())+";"+QString::number(rgh->getSp())+";"+QString::number(rgt->getSp())+";"+QString::number(zb->getZbL()->getFd());
}

void MainWindow::odebranie()
{
    this->repaint();
    if(zb->getZbL()->getHAkt()>konH->getProgG()||zb->getZbL()->getHAkt()<konH->getProgD()){
        konH->migaj();
        ui->awaria->setEnabled(true);
    }
    else {konH->wylacz();ui->awaria->setEnabled(false);}
    if(zb->getZbL()->getTAkt()>konT->getProgG()||zb->getZbL()->getTAkt()<konT->getProgD()){
        konT->migaj();
        ui->awaria->setEnabled(true);
    }
    else{
        if(zb->getZbL()->getHAkt()>konH->getProgG()||zb->getZbL()->getHAkt()<konH->getProgD())konT->wylacz();
        else {konT->wylacz();ui->awaria->setEnabled(false);}
    }
    ui->wysokosc->display(zb->getZbL()->getHAkt());
    ui->temperatura->display(zb->getZbL()->getTAkt());
    if(ui->zlos->checkState()){
            zb->getZbL()->setRandomDis();
            ui->Fd->setValue(zb->getZbL()->getFd());
    }

    if(dane.is_open()){
        this->zbieranieDanych();
        dane<<liniadanych.toStdString()<<endl;
    }


    if(licznik>=4&&ui->checkBox->checkState()){
        licznik=5;
        rgh->control(zb->getZbL()->getHistH());
        if(zb->getZbL()->getFh()-rgh->getSter_1()<0){
            zb->getZbL()->setFlowHot(0);
            ui->Fh->setValue(0);
            ui->Fh->editingFinished();
            }
        else{
            zb->getZbL()->setFlowHot(zb->getZbL()->getFh()-rgh->getSter_1());
            ui->Fh->setValue(zb->getZbL()->getFh()-rgh->getSter_1());
            ui->Fh->editingFinished();
            }
    }

    if(licznik>=4&&ui->checkBox_2->checkState()){
        licznik=5;
        rgt->control(zb->getZbL()->getHistT());
        if(zb->getZbL()->getFc()+rgt->getSter_1()<0){
            zb->getZbL()->setFlowCold(0);
            ui->Fc->setValue(0);
            ui->Fc->editingFinished();
            }
        else{
            zb->getZbL()->setFlowCold(zb->getZbL()->getFc()+rgt->getSter_1());
            ui->Fc->setValue(zb->getZbL()->getFc()+rgt->getSter_1());
            ui->Fc->editingFinished();
            }
    }

    if(licznik>=4&&ui->checkBox_3->checkState()){
        licznik=5;
        rlqr->control(zb->getZbL()->getHistH(), zb->getZbL()->getHistT());
        if(ZbiornikL::Fh_pp+rlqr->getSter_1()<0){
            zb->getZbL()->setFlowHot(0);
            ui->Fh->setValue(0);
            ui->Fh->editingFinished();
            }
        if(ZbiornikL::Fc_pp+rlqr->getSter_2()<0){
            zb->getZbL()->setFlowCold(0);
            ui->Fc->setValue(0);
            ui->Fc->editingFinished();
            }
        else{
            zb->getZbL()->setFlowCold(zb->getZbL()->getFc()+rlqr->getSter_2());
            zb->getZbL()->setFlowHot(zb->getZbL()->getFh()+rlqr->getSter_1());
            ui->Fc->setValue(zb->getZbL()->getFc()+rlqr->getSter_2());
            ui->Fc->editingFinished();
            ui->Fh->setValue(zb->getZbL()->getFh()+rlqr->getSter_1());
            ui->Fh->editingFinished();

        }
    }
    licznik++;
    if(ui->tem->checkState()) {wykres->setWybor(2); wykres->setMax(ZbiornikL::t_max); wykres->setMin(ZbiornikL::t_min);}
    else if(ui->wys->checkState()) {wykres->setWybor(1); wykres->setMax(ZbiornikL::h_max); wykres->setMin(0);}
    else wykres->setWybor(0);
    wykres->zmianaHistori(zb->getZbL()->getHAkt(), rlqr->getSpH(), zb->getZbL()->getTAkt(), rlqr->getSpT());
    wykres->repaint();
}


void MainWindow::on_Fh_editingFinished()
{
    zb->getZbL()->setFlowHot(ui->Fh->value());
    zb->getZblin()->setFlowHot(ui->Fh->value());
}

void MainWindow::on_Fc_editingFinished()
{
    zb->getZbL()->setFlowCold(ui->Fc->value());
    zb->getZblin()->setFlowCold(ui->Fc->value());
}

void MainWindow::on_Fd_editingFinished()
{
    zb->getZbL()->setFlowDis(ui->Fd->value());
    zb->getZblin()->setFlowDis(ui->Fd->value());
}

void MainWindow::on_pp_clicked()
{
    ui->Fc->setValue(ZbiornikL::Fc_pp);
    ui->Fd->setValue(ZbiornikL::Fd_pp);
    ui->Fh->setValue(ZbiornikL::Fh_pp);
    ui->Fc->editingFinished();
    ui->Fd->editingFinished();
    ui->Fh->editingFinished();
    ui->sp->setValue(17.44);
    ui->spT->setValue(39.72);
    rgh->setSp(17.44);
    rgt->setSp(39.72);
}

void MainWindow::on_sp_editingFinished()
{
    rgh->setSp(ui->sp->value());
    rlqr->setSpH(ui->sp->value());
}


void MainWindow::on_spT_editingFinished()
{
    rgt->setSp(ui->spT->value());
    rlqr->setSpT(ui->spT->value());
}

void MainWindow::on_start_clicked()
{
    zb->start();
    zb->getO()->startuj();
}

void MainWindow::on_zbieranieD_clicked()
{
    this->zb->stop();
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    QString timeS = QString::number(time.hour())+";"+QString::number(time.minute())+";"+QString::number(time.second());
    QString dataS = QString::number(date.month())+"."+QString::number(date.daysInMonth())+",";
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    "C:/",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    QString full = dir+"/"+dataS+timeS+".txt";
    string t = full.toStdString();
    qDebug()<<full;
    dane.open(t.c_str());
    dane<<"h_akt;t_akt;sp_h;sp_t;Fh"<<endl;
    this->zb->start();
}

void MainWindow::on_zbieranieD_K_clicked()
{
    dane.close();
}

void MainWindow::on_kp_editingFinished()
{
    rgh->setKp(ui->kp->value());
}

void MainWindow::on_awaria_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->zlos->setChecked(false);
    ui->pp->clicked(true);
    ui->awaria->setEnabled(false);
}

void MainWindow::on_tem_clicked()
{
    ui->wys->setChecked(false);
    wykres->czyscHistorieH();
    wykres->czyscHistorieT();
    if(ui->tem->checkState()) {wykres->setWybor(2); wykres->setMax(ZbiornikL::t_max); wykres->setMin(ZbiornikL::t_min);}
    wykres->zerujLicznik();
}

void MainWindow::on_wys_clicked()
{
    ui->tem->setChecked(false);
    wykres->czyscHistorieT();
    wykres->czyscHistorieH();
    if(ui->wys->checkState()) {wykres->setWybor(1); wykres->setMax(ZbiornikL::h_max); wykres->setMin(0);}
    wykres->zerujLicznik();
}

void MainWindow::on_ki_editingFinished()
{
    rgh->setKi(ui->ki->value());
}

void MainWindow::on_kd_editingFinished()
{
    rgh->setKd(ui->kd->value());
}

void MainWindow::on_stop_clicked()
{
    ui->wys->setChecked(false);
    ui->tem->setChecked(false);
    wykres->czyscHistorieT();
    wykres->czyscHistorieH();
    wykres->repaint();
    ui->pp->click();
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->zlos->setChecked(false);
    zb->stop();
    zb->reset();
}
