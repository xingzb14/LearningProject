#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QWidget>
class userWindow:public QWidget
{
    Q_OBJECT
public:
    userWindow();
    ~userWindow();
private:
    QLabel usernameLabel;
    //一系列用户信息
    QLabel learningTime;
    QLabel haveRecited;
    QLabel currentBook;
    QLabel currentWordNumber;
    QPushButton newWordButton;
};

#endif // USERWINDOW_H
