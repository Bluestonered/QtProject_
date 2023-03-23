#include <QApplication>

#include "View/StartWindow.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    StartWindow a;
    a.show();
    return app.exec();
}
