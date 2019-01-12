#-------------------------------------------------
#
# Project created by QtCreator 2019-01-02T15:19:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gestion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    modele\
    controleur\
    vue

SOURCES += \
        main.cpp \
    vue/fcreation.cpp \
    modele/gesdessin.cpp \
    modele/testergesdessin.cpp \
    controleur/ctrlcreation.cpp

HEADERS += \
    vue/fcreation.h \
    modele/gesdessin.h \
    modele/testergesdessin.h \
    controleur/ctrlcreation.h

FORMS += \
    vue/fcreation.ui

win32:CONFIG(release, debug|release): LIBS += -L./../build-dllcreer-Desktop_Qt_5_11_1_MinGW_32bit-Debug/release/ -ldllcreer
else:win32:CONFIG(debug, debug|release): LIBS += -L./../build-dllcreer-Desktop_Qt_5_11_1_MinGW_32bit-Debug/debug/ -ldllcreer
else:unix: LIBS += -L./../build-dllcreer-Desktop_Qt_5_11_1_MinGW_32bit-Debug/ -ldllcreer


INCLUDEPATH += ./../dllcreer
DEPENDPATH += ./../dllcreer

win32:CONFIG(release, debug|release): LIBS += -L./../build-dlldessiner-Desktop_Qt_5_11_1_MinGW_32bit-Debug/release/ -ldlldessiner
else:win32:CONFIG(debug, debug|release): LIBS += -L./../build-dlldessiner-Desktop_Qt_5_11_1_MinGW_32bit-Debug/debug/ -ldlldessiner
else:unix: LIBS += -L./../build-dlldessiner-Desktop_Qt_5_7_0_MinGW_32bit-Debug/ -ldlldessiner

INCLUDEPATH += ./../dlldessiner
DEPENDPATH += ./../dlldessiner

RESOURCES += \
    logo_gestion_formes.qrc
