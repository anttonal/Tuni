TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        sudoku.cpp

HEADERS += \
    sudoku.hh

DISTFILES += \
    build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/input.txt
