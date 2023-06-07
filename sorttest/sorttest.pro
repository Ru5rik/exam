QT += testlib network
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_heapsort_testcase.cpp \
    ../hallServer/client.cpp

HEADERS += \
    ../hallServer/client.h
