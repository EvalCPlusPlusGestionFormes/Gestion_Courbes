#-------------------------------------------------
#
# Project created by QtCreator 2017-02-01T09:28:55
#
#-------------------------------------------------

QT       -= gui

TARGET = dllcreer
TEMPLATE = lib

DEFINES += CREER_LIBRARY

HEADERS += creer_global.h \
    cercle.h \
    coldessins.h \
    cosinus.h \
    demicercle.h \
    dessin.h \
    exponentiel.h \
    fonction.h \
    ligne.h \
    point.h \
    puissance2.h \
    racinecarre.h \
    rectangle.h \
    repere.h \
    sinus.h \
    trace.h \
    trigo.h \
    testerdllcreer.h \
    maths.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}


SOURCES += \
    cercle.cpp \
    coldessins.cpp \
    demicercle.cpp \
    dessin.cpp \
    ligne.cpp \
    rectangle.cpp \
    repere.cpp \
    trace.cpp \
    trigo.cpp \
    testerdllcreer.cpp
