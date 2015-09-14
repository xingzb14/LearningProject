#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QWidget>
#include "learningwindow.h"
#include "phrasewindow.h"
#include "translatewindow.h"
#include "morewindow.h"
class userWindow:public QWidget
{
    Q_OBJECT
public:
    userWindow();
    ~userWindow();
private:
    QLabel background;
    QLabel usernameLabel;
    //一系列用户信息
    QLabel learningTime;    //学习时间
    QLabel haveWords;       //已经学过单词
    QLabel havePhrases;     //已经学过短语
    QLabel newWordNumber;   //生词本单词书
    QLabel currentBook;     //当前词库
    QLabel nowFrequency;    //最近学习频率
    QPushButton newWordButton;  //管理生词本

    //导航栏
    QPushButton translateButton;
    QPushButton phrase;
    QPushButton wordlearning;
    QPushButton aboutUser;
    QPushButton more;
private slots:
    void openTranslate();
    void openWordLearning();
    void openPhraseLearning();
//    void openUser();
    void openSetting();
};

#endif // USERWINDOW_H
