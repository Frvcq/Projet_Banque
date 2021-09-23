TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        comptebancaire.cpp \
        compteclients.cpp \
        compteepargne.cpp \
        main.cpp \
        menu.cpp

HEADERS += \
    comptebancaire.h \
    compteclients.h \
    compteepargne.h \
    menu.h

DISTFILES += \
    Documentation \
    client.txt \
    compteBancaire.txt \
    compteEpargne.txt
