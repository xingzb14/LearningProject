#include "phrasewindow.h"

phraseWindow::phraseWindow()
{
    this->setMaximumSize(270, 480);
    this->setMinimumSize(270, 480);
    setWindowFlags(Qt::FramelessWindowHint);
    background = new QLabel(this);
    background->setStyleSheet("background:url(:/image/phraseWindow.jpg)");
    background->setGeometry(0, 0, this->width(), this->height());
    //导航栏
    translateButton.setParent(this);
    translateButton.setStyleSheet("background-color:transparent;border:0px groove gray;border-radius:19px;padding:2px 4px");
    phrase.setParent(this);
    phrase.setStyleSheet("background-color:transparent;border:0px groove gray;border-radius:19px;padding:2px 4px");
    wordlearning.setParent(this);
    wordlearning.setStyleSheet("background-color:transparent;border:0px groove gray;border-radius:19px;padding:2px 4px");
    aboutUser.setParent(this);
    aboutUser.setStyleSheet("background-color:transparent;border:0px groove gray;border-radius:19px;padding:2px 4px");
    more.setParent(this);
    more.setStyleSheet("background-color:transparent;border:0px groove gray;border-radius:19px;padding:2px 4px");

    wordlearning.setGeometry(7, 425, 38, 38);
    phrase.setGeometry(61, 425, 38, 38);
    translateButton.setGeometry(115, 425, 38, 38);
    aboutUser.setGeometry(169, 425, 38, 38);
    more.setGeometry(222, 425, 38, 38);

    connect(&wordlearning, SIGNAL(clicked()), this, SLOT(openWordLearning()));
    connect(&translateButton, SIGNAL(clicked()), this, SLOT(openTranslate()));
    connect(&aboutUser, SIGNAL(clicked()), this, SLOT(openUser()));
    connect(&more, SIGNAL(clicked()), this, SLOT(openSetting()));

}

phraseWindow::~phraseWindow()
{

}
//private slots
void phraseWindow::openTranslate()
{
    translateWindow *translatewindow = new translateWindow();
    translatewindow->show();
    this->close();
}

void phraseWindow::openWordLearning()
{
    mainWindow *mainwindow = new mainWindow();
    mainwindow->show();
    this->close();
}
void phraseWindow::openUser()
{
    userWindow *userwindow = new userWindow();
    userwindow->show();
    this->close();
}
void phraseWindow::openSetting()
{
    moreWindow *morewindow = new moreWindow();
    morewindow->show();
    this->close();
}
