TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
        gradecalculator.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
    gradecalculator.hh \
    mainwindow.hh

QT += widgets

FORMS += \
    mainwindow.ui
