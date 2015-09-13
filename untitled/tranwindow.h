#ifndef TRANWINDOW_H
#define TRANWINDOW_H
#include "loginwindow.h"
#include "registerwindow.h"
#include <QComboBox>
class tranWindow:public QMainWindow
{
    Q_OBJECT
public:
    tranWindow();
private:
    QLabel background;
    QLabel topLabel;                //顶层标签
    QPushButton wordNumberTest;     //词汇量测试
    QPushButton enterDirectly;      //直接进入
    QLabel classificationLabel;     //标签
    QComboBox classificationBox;    //词汇量选框

    QPoint last;
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
};
#endif // TRANWINDOW_H
