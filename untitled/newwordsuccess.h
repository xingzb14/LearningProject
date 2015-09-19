#ifndef NEWWORDSUCCESS_H
#define NEWWORDSUCCESS_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "mainwindow.h"
#include "data.h"


class newWordSuccess:public QWidget
{
    Q_OBJECT
public:
    newWordSuccess(INFO info, User *user);
    ~newWordSuccess();
private:
    User *user;
    INFO info;
    QLabel *background;
    QLabel *sum;
    QLabel *right;
    QLabel *wrong;
    QLabel *remove;
    QPushButton *backbutton;
public:
    void setSum(int sum);
    void setRight(int right);
    void setWrong(int wrong);
    void setRemove(int remove);
    void setInfo()
    {
        setSum(info.sum);
        setRight(info.right);
        setWrong(info.wrong);
        setRemove(info.remove);
    }

private slots:
    void back();

};

#endif // NEWWORDSUCCESS_H
