#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include  <QWidget>
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

};

#endif // MAINWINDOW_H
