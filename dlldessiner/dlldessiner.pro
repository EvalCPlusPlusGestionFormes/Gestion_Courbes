#-------------------------------------------------
#
# Project created by QtCreator 2017-02-01T09:29:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dlldessiner
TEMPLATE = lib

DEFINES += DESSINER_LIBRARY

SOURCES += \
    fdessiner.cpp \
    fdessinertrt.cpp \
    testerdlldessiner.cpp \
    dessinerpolygones.cpp

HEADERS +=\
        dessiner_global.h \
    fdessiner.h \
    fdessinertrt.h \
    testerdlldessiner.h \
    dessinerpolygones.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    fdessiner.ui
