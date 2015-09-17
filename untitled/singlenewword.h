#ifndef SINGLENEWWORD_H
#define SINGLENEWWORD_H
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QLayout>
#include <QRadioButton>
#include <QGroupBox>
#include <QWaitCondition>
#include <QTime>
#include <QTimer>
#include <QCoreApplication>
#include <QDebug>
#include "newwordsuccess.h"
//#include "data.h"
typedef struct option
{
    QString spell;
    QString A;
    QString B;
    QString C;
    QString D;
    int index;
}OPTION;

class singleNewword:public QWidget
{
    Q_OBJECT
public:
    singleNewword();
    ~singleNewword();
private:
    QLabel *background;
    QLabel *spellLabel;
    QLabel *remindLabel;
    QRadioButton *optionsA;
    QRadioButton *optionsB;
    QRadioButton *optionsC;
    QRadioButton *optionsD;

    QPushButton *nextButton;
    QPushButton *backButton;
    int nowindex;
public:

    int getRadioIndex();

private slots:
    void nextWord();
    void setInfo(OPTION option);     //切换信息
    void back();

};





#endif // SINGLENEWWORD_H
