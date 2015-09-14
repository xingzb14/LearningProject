#ifndef PHRASEWINDOW_H
#define PHRASEWINDOW_H
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include "learningwindow.h"
#include "mainwindow.h"
#include "userwindow.h"
#include "translatewindow.h"
#include "morewindow.h"
class phraseWindow:public QWidget
{
    Q_OBJECT
public:
    phraseWindow();
    ~phraseWindow();
private:
    QLabel *background;
    QPushButton *search;
    QLabel havefinished;        //已完成
    QLabel unfinished;          //未完成
    QLabel todayFinished;       //今天所学
    QLabel todaytoReview;       //今天复习
    QPushButton learningPharse;
    QPushButton reviewPhrase;
    //导航按钮
    QPushButton translateButton;
    QPushButton phrase;
    QPushButton wordlearning;
    QPushButton aboutUser;
    QPushButton more;

private slots:
    void openTranslate();
    void openWordLearning();
//    void openPhraseLearning();
    void openUser();
    void openSetting();
};

#endif // PHRASEWINDOW_H
