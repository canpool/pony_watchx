TOP_DIR = $$PWD/../../../..

LV_ADV_DIR = $$TOP_DIR/3rdparty/lv_advanced
3RDPARTY_DIR = $$LV_ADV_DIR/3rdparty

HEADERS += \
    $$files($$PWD/*.h, true)

SOURCES += \
    $$files($$PWD/*.c, true)

INCLUDEPATH += \
    $$PWD \
    $$3RDPARTY_DIR

LVGL_DIR = $$3RDPARTY_DIR/lvgl

include($$LV_ADV_DIR/lvgl.pri)
include($$LV_ADV_DIR/lv_advanced.pri)
include($$3RDPARTY_DIR/freetype/freetype.pri)
include($$TOP_DIR/watchx.pri)
