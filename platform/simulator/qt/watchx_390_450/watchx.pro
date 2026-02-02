QT += core gui widgets

CONFIG += c++11 console

TEMPLATE = app
DESTDIR = ../bin

HEADERS += \
    $$PWD/lv_conf.h

SOURCES += \
    $$PWD/main.cpp

INCLUDEPATH += $$PWD

DEFINES += LV_HOR_RES_MAX=390 LV_VER_RES_MAX=450 \
    LV_QT_WORKING_DIR=\\\"$$OUT_PWD/$$DESTDIR\\\"

include($$PWD/../common/common.pri)
