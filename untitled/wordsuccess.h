#ifndef WORDSUCCESS_H
#define WORDSUCCESS_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "mainwindow.h"
class wordSuccess:public QWidget
{
    Q_OBJECT
public:
    wordSuccess();
private:
    QLabel *background;
    QPushButton *backButton;
    QPushButton *topBackButton;
private slots:
    void nextStage();
    void back();
};



#endif // WORDSUCCESS_H
