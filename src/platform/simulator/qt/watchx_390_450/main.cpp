#include "lv_qt_window.h"
#include "lv_main.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lv_adv_setup();
    LvQtWindow w(false, 100);
    w.setWindowTitle("WatchX Simulator");
    w.show();
    return a.exec();
}
