QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += tst_path_test.cpp \
           ../gameboard.cpp \
           ../button.cpp

HEADERS += \
           ../gameboard.hh \
           ../button.hh


