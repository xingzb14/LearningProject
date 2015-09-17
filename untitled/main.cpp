#include <QApplication>
#include <QSplashScreen>
#include <QElapsedTimer>
#include "loginWindow.h"
//#include "tranwindow.h"
//#include "mainwindow.h"
//#include "translatewindow.h"
//#include "userwindow.h"
//#include "newwordmanagewindow.h"
//#include "learningwindow.h"
//#include "morewindow.h"
//#include "phrasewindow.h"
#include "singleword.h"
#include "singlenewword.h"
#include "newwordsuccess.h"
#include "phrasesuccess.h"
#include "singlephrase.h"
//#include <QTime>
#include <QString>
WORD word = {"spell", "translation", "label", "englishMeaning"
             ,"example", "exampleMeaninglonglonglong"};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    singlePhrase window;
    QSplashScreen splash(QPixmap(":/image/animation.jpg"));         //以下都是开场动画效果
    splash.setDisabled(true);
    splash.show();
    app.processEvents();
    QElapsedTimer t;
    t.start();
    while(t.elapsed()<2000)
    {
        QCoreApplication::processEvents();
    }
    splash.finish(&window);
    window.show();


    return app.exec();
}
