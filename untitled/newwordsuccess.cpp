#include "newwordsuccess.h"

newWordSuccess::newWordSuccess(INFO info)
{
    this->info = info;
    this->setMaximumSize(270, 480);
    this->setMinimumSize(270, 480);
    this->setWindowFlags(Qt::FramelessWindowHint);
    background = new QLabel(this);
    background->setStyleSheet("background:url(:/image/newWordFinish.jpg)");
    background->setGeometry(0, 0, this->width(), this->height());
    sum = new QLabel(this);
    right = new QLabel(this);
    wrong = new QLabel(this);
    remove = new QLabel(this);
    sum->setGeometry(112, 140, 60, 60);
    sum->setStyleSheet("font-size:25px");
    sum->setAlignment(Qt::AlignCenter);
    right->setGeometry(112, 196, 60, 60);
    right->setAlignment(Qt::AlignCenter);
    right->setStyleSheet("font-size:25px");
    wrong->setGeometry(112, 255, 60, 60);
    wrong->setAlignment(Qt::AlignCenter);
    wrong->setStyleSheet("font-size:25px");
    remove->setGeometry(112, 315, 60, 60);
    remove->setStyleSheet("font-size:25px");
    remove->setAlignment(Qt::AlignCenter);
    backbutton = new QPushButton(this);
    backbutton->setGeometry(69, 417, 125, 45);
    backbutton->setStyleSheet("background-color:transparent");
    setInfo();
    connect(backbutton, SIGNAL(clicked()), this, SLOT(back()));

}
//private slots
void newWordSuccess::back()
{
    mainWindow *window = new mainWindow();
    window->show();
    qDebug() << "hello";
    this->close();
}

//public
void newWordSuccess::setSum(int sum)
{
    QString string = QString::number(sum);
    this->sum->setText(string);
}
void newWordSuccess::setRight(int right)
{
    QString string = QString::number(right);
    this->right->setText(string);
}
void newWordSuccess::setWrong(int wrong)
{
    QString string = QString::number(wrong);
    this->wrong->setText(string);
}
void newWordSuccess::setRemove(int remove)
{
    QString string = QString::number(remove);
    this->remove->setText(string);
}

newWordSuccess::~newWordSuccess()
{

}

