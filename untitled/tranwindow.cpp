#include "tranwindow.h"
tranWindow::tranWindow(QWidget *parent)
{
    this->resize(270, 480);
    setWindowFlags(Qt::FramelessWindowHint);
    background.setParent(this);
    background.setStyleSheet("background:url(:/image/tranWindow.jpg)");
    background.setGeometry(0, 0, this->width(), this->height());

    QStringList bookList;
    bookList << "日常英语" << "高中词汇" <<" 四级词汇" << "六级词汇" << "托福词汇" << "雅思词汇" << "GRE词汇" << "更多";

    classificationBox.setParent(this);
    classificationBox.setGeometry(40, 170, 190, 25);
    classificationBox.addItems(bookList);
    wordNumberTest.setParent(this);
    wordNumberTest.setGeometry(62, 307, 154, 53);
    wordNumberTest.setStyleSheet("background-color:transparent");

    enterDirectly.setParent(this);
    enterDirectly.setGeometry(62, 376, 154, 53);
    enterDirectly.setStyleSheet("background-color:transparent");
    connect(&enterDirectly, SIGNAL(clicked()), this, SLOT(enterIn()));
}
//public slots
void tranWindow::enterIn()
{
    mainWindow *mainwindow = new mainWindow();
    mainwindow->show();
    this->close();
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
