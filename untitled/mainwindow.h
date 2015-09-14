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
class mainWindow:public QMainWindow
{
    Q_OBJECT
public:
    mainWindow();
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

};

#endif // MAINWINDOW_H
