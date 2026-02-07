HEADERS += \
    $$files($$PWD/include/*.h, true) \
    $$files($$PWD/src/*.h, true)

SOURCES += \
    $$files($$PWD/src/*.c, true)

INCLUDEPATH += \
    $$PWD/include \
    $$PWD/src \
    $$PWD/src/apps/common \
    $$PWD/src/misc \
    $$PWD/platform/common

DEFINES += WX_USE_FILE_RESOURCE \
    LV_ADV_IMG_RES_PATH=\\\"/res/images\\\"

build_res.commands = python $$PWD/3rdparty/lv_advanced/scripts/build_res.py \
    -i $$PWD/res -o $$DESTDIR/res --no-parents --width $$DISPLAY_WIDTH --height $$DISPLAY_HEIGHT
build_res.target = build_res
QMAKE_EXTRA_TARGETS += build_res
PRE_TARGETDEPS += build_res
