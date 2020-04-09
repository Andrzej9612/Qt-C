#-------------------------------------------------
#
# Project created by QtCreator 2020-02-22T18:49:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Symulacja
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ZbiornikG.cpp \
    ZbiornikL.cpp \
    SkalaH.cpp \
    Regulator.cpp \
    ZbiornikLinear.cpp \
    RegulatorLQR.cpp \
    Przeplyw.cpp \
    Kontrolka.cpp \
    WykresG.cpp

HEADERS  += mainwindow.h \
    ZbiornikG.h \
    ZbiornikL.h \
    SkalaH.h \
    Regulator.h \
    ZbiornikLinear.h \
    RegulatorLQR.h \
    Przeplyw.h \
    Kontrolka.h \
    WykresG.h

FORMS    += mainwindow.ui
