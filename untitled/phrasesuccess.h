#ifndef PHRASESUCCESS_H
#define PHRASESUCCESS_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "mainwindow.h"

class phraseSuccess:public QWidget
{
    Q_OBJECT
public:
    phraseSuccess();
private:
    QLabel *background;
    QPushButton *backButton;
    QPushButton *topBackButton;

private slots:
    void nextStage();
    void back();
};

#endif // PHRASESUCCESS_H
