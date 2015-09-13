#ifndef TRANSLATEWINDOW_H
#define TRANSLATEWINDOW_H
#include "mainwindow.h"
#include <QWidget>
#include <QTextEdit>
class translateWindow:public QWidget
{
    Q_OBJECT
public:
    translateWindow();
    ~translateWindow();
private:
    QTextEdit textEdit1;
    QTextEdit textEdit2;
    QPushButton translationButton;
};

#endif // TRANSLATEWINDOW_H
