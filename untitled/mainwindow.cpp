#include "mainwindow.h"

mainWindow::mainWindow()
{
    this->resize(270, 480);
    setWindowFlags(Qt::FramelessWindowHint);
    background.setParent(this);
    background.setStyleSheet("background-color:lightblue");
    background.setGeometry(0, 0, this->width(), this->height());
    topLabel.setParent(this);
    topLabel.setStyleSheet("background-color:white");
    topLabel.setGeometry(0, 0, this->width(), this->height()/16);
    topLabel.setText("过渡界面");
    //单词解释
    searchWordEdit.setParent(this);
    searchWordEdit.setGeometry(40, 3, 190, 25);
    //浮动窗口
    remindLabel.setParent(this);
    remindLabel.setGeometry(30, 35, 210, 40);
    remindLabel.setText("这里会显示一些浮动信息");
    remindLabel.setAlignment(Qt::AlignCenter);
    //已完成，未完成
    finishedLabel.setParent(this);
    unfinishedLabel.setParent(this);
    finishedLabel.setGeometry(50, 140, 170, 40);
    unfinishedLabel.setGeometry(50, 180, 170, 40);
    finishedLabel.setText("已完成");
    finishedLabel.setAlignment(Qt::AlignCenter|Qt::AlignBottom);
    unfinishedLabel.setText("未完成");
    unfinishedLabel.setAlignment(Qt::AlignCenter|Qt::AlignBottom);
    //两个并排 今天学习， 待复习
    todayStudying.setParent(this);
    todayStudying.setGeometry(30, 300, 75, 20);
    todayStudying.setText("今天学习");
    toreviewToday.setParent(this);
    toreviewToday.setGeometry(165, 300, 75, 20);
    toreviewToday.setText("今天待复习");
    //学习 复习 生词本
    learn.setParent(this);
    review.setParent(this);
    noteWordLearning.setParent(this);
    learn.setGeometry(20, 380, 60, 30);
    learn.setText("学习");
    review.setGeometry(90, 380, 60, 30);
    review.setText("复习");
    noteWordLearning.setGeometry(160, 380, 90, 30);
    noteWordLearning.setText("学习生词");
    //选项卡
    translateButton.setParent(this);
    phrase.setParent(this);
    wordlearning.setParent(this);
    aboutUser.setParent(this);
    more.setParent(this);
    translateButton.setGeometry(0, 430, 54, 40);
    translateButton.setText("翻译");
    phrase.setGeometry(54, 430, 54, 40);
    phrase.setText("短语");
    wordlearning.setGeometry(108, 430, 54, 40);
    wordlearning.setText("单词");
    aboutUser.setGeometry(162, 430, 54, 40);
    aboutUser.setText("我的");
    more.setGeometry(216, 430, 54, 40);
    more.setText("更多");
}

mainWindow::~mainWindow()
{

}

