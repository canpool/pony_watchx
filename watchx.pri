HEADERS += \
    $$files($$PWD/include/*.h, true) \
    $$files($$PWD/src/apps/*.h, true) \
    $$files($$PWD/src/init/*.h, true) \
    $$files($$PWD/src/misc/*.h, true)

SOURCES += \
    $$files($$PWD/src/apps/*.c, true) \
    $$files($$PWD/src/init/*.c, true) \
    $$files($$PWD/src/misc/*.c, true)

INCLUDEPATH += \
    $$PWD/include \
    $$PWD/src/apps/common \
    $$PWD/src/misc \
    $$PWD/src/platform/common

DEFINES += WX_USE_FILE_RESOURCE \
    LV_ADV_IMG_RES_PATH=\\\"/res/images\\\"

build_res.commands = python $$PWD/3rdparty/lv_advanced/scripts/build_res.py \
    -i $$PWD/resources -o $$DESTDIR/res --no-parents
build_res.target = build_res
QMAKE_EXTRA_TARGETS += build_res
PRE_TARGETDEPS += build_res
