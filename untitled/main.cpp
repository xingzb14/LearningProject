#include <QApplication>
#include "loginWindow.h"
#include "tranwindow.h"
#include "mainwindow.h"
#include "translatewindow.h"
#include "userwindow.h"
#include "newwordmanagewindow.h"
#include "learningwindow.h"
#include "morewindow.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    loginWindow window;
    window.show();
    return app.exec();
}
