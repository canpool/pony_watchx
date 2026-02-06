QT += core gui widgets

CONFIG += c++11 console

TEMPLATE = app
DESTDIR = ../bin

HEADERS += \
    $$PWD/lv_conf.h

SOURCES += \
    $$PWD/main.cpp

INCLUDEPATH += $$PWD

DISPLAY_WIDTH = 390
DISPLAY_HEIGHT = 450

DEFINES += LV_HOR_RES_MAX=$$DISPLAY_WIDTH LV_VER_RES_MAX=$$DISPLAY_HEIGHT \
    LV_QT_WORKING_DIR=\\\"$$OUT_PWD/$$DESTDIR\\\"

include($$PWD/../common/common.pri)
