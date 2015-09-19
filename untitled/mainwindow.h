#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QWidget>
#include <QMouseEvent>
#include "phrasewindow.h"
#include "translatewindow.h"
#include "userwindow.h"
#include "morewindow.h"
#include "mainwindow.h"
#include "singleword.h"
#include "singlenewword.h"
#include "user.h"
class mainWindow:public QMainWindow
{
    Q_OBJECT
public:
    mainWindow(User *user);
    ~mainWindow();
private:
    QLabel background;
    QLabel topLabel;
    QLineEdit searchWordEdit;
    QPushButton searchButton;
    QLabel meaningLabel;
    QLabel remindLabel;
    QLabel finishedLabel;
    QLabel unfinishedLabel;
    QLabel todayStudying;       //两个并排
    QLabel toreviewToday;
    QPushButton learn;          //三个并排按钮
    QPushButton review;
    QPushButton noteWordLearning;

//    QLabel bottomLabel;
    QPushButton translateButton;
    QPushButton phrase;
    QPushButton wordlearning;
    QPushButton aboutUser;
    QPushButton more;
    QHBoxLayout bottomLayout;
    QPoint last;

    int wordNumber();
public:
    //发送
    //获取拼写
    User *user;

    QString getSpell() { return searchWordEdit.text(); }

    //接收
    void setMeaning(QString string) { meaningLabel.setText(string); }
    void setRemind(QString string)  { remindLabel.setText(string);  }
    void setFinished(QString string) { finishedLabel.setText(string); }
    void setUnfinished(QString string) { unfinishedLabel.setText(string); }
    void setTodayStudying(QString string) { todayStudying.setText(string); }
    void setToReview(QString string) { toreviewToday.setText(string); }


protected:

    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private slots:
    void openTranslate();
//    void openWordLearning();
    void openPhraseLearning();
    void openUser();
    void openSetting();

    void startLearning();
    void startLearningNew();
    void startReview();

};

#endif // MAINWINDOW_H
