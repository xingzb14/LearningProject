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
#include "singlephrase.h"
class phraseWindow:public QWidget
{
    Q_OBJECT
public:
    phraseWindow();
    ~phraseWindow();
private:
    QLabel *background;
    QLineEdit searchWordEdit;
    QPushButton searchButton;
    QLabel meaningLabel;
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

public:
    void setMeaning(QString string) { meaningLabel.setText(string); }
    void setFinished(QString string) { havefinished.setText(string); }
    void setUnfinished(QString string) { unfinished.setText(string); }
    void setTodayStudying(QString string) { todayFinished.setText(string); }
    void setToReview(QString string) { todaytoReview.setText(string); }

private slots:
    void openTranslate();
    void openWordLearning();
//    void openPhraseLearning();
    void openUser();
    void openSetting();
    void startLearning();
    void startReviewing();
};

#endif // PHRASEWINDOW_H
