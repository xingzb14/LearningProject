#include "tranwindow.h"

tranWindow::tranWindow()
{
    this->resize(270, 480);
    setWindowFlags(Qt::FramelessWindowHint);
    background.setParent(this);
    background.setStyleSheet("background-color:lightblue");
    background.setGeometry(0, 0, this->width(), this->height());
    topLabel.setParent(this);
    topLabel.setGeometry(0, 0, this->width(), this->height()/18);
    topLabel.setStyleSheet("background-color:white");
    topLabel.setText("过渡界面");
    topLabel.setAlignment(Qt::AlignCenter);

    classificationLabel.setParent(this);
    classificationLabel.setGeometry(40, 120, 190, 40);
    classificationLabel.setText("请输入您的词汇量范围");
    classificationBox.setParent(this);
    classificationBox.setGeometry(40, 170, 190, 35);
    wordNumberTest.setParent(this);
    wordNumberTest.setGeometry(50, 270, 170, 50);
    wordNumberTest.setText("词汇量测试");

    QLabel *label_temp = new QLabel(this);
    label_temp->setGeometry(40, 220, 190, 40);
    label_temp->setText("不知道词汇量，请进行测试");

    enterDirectly.setParent(this);
    enterDirectly.setGeometry(50, 340, 170, 50);
    enterDirectly.setText("直接进入");
}



//protected
void tranWindow::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void tranWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();

    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void tranWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();
    move(x()+dx, y()+dy);
}
