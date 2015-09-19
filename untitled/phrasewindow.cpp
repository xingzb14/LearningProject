#include "phrasewindow.h"

phraseWindow::phraseWindow(User *user):user(user)
{
    this->setMaximumSize(270, 480);
    this->setMinimumSize(270, 480);
    setWindowFlags(Qt::FramelessWindowHint);
    background = new QLabel(this);
    background->setStyleSheet("background:url(:/image/phraseWindow.jpg)");
    background->setGeometry(0, 0, this->width(), this->height());

    searchWordEdit.setParent(this);
    searchWordEdit.setGeometry(70, 5, 130, 25);
    meaningLabel.setParent(this);
    meaningLabel.setGeometry(88, 38, 150, 20);
    meaningLabel.setStyleSheet("background-color:transparent");
    searchButton.setParent(this);
    searchButton.setGeometry(210, 5, 20, 20);
    searchButton.setText("搜索");
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

    learningPharse.setParent(this);
    learningPharse.setGeometry(32, 360, 95, 38);
    reviewPhrase.setParent(this);
    reviewPhrase.setGeometry(145, 360, 93, 38);
    learningPharse.setStyleSheet("background-color:transparent");
    reviewPhrase.setStyleSheet("background-color:transparent");
    connect(&wordlearning, SIGNAL(clicked()), this, SLOT(openWordLearning()));
    connect(&translateButton, SIGNAL(clicked()), this, SLOT(openTranslate()));
    connect(&aboutUser, SIGNAL(clicked()), this, SLOT(openUser()));
    connect(&more, SIGNAL(clicked()), this, SLOT(openSetting()));
    connect(&learningPharse, SIGNAL(clicked()), this, SLOT(startLearning()));
    connect(&reviewPhrase, SIGNAL(clicked()), this, SLOT(startReviewing()));
}

phraseWindow::~phraseWindow()
{

}
//private slots
void phraseWindow::startLearning()  //开始学习
{
    singlePhrase *window = new singlePhrase();
    window->show();
    this->close();
}
void phraseWindow::startReviewing() //复习
{
    singlePhrase *window = new singlePhrase();
    window->show();
    this->close();
}

void phraseWindow::openTranslate()
{
    translateWindow *translatewindow = new translateWindow(user);
    translatewindow->show();
    this->close();
}

void phraseWindow::openWordLearning()
{
    mainWindow *mainwindow = new mainWindow(user);
    mainwindow->show();
    this->close();
}
void phraseWindow::openUser()
{
    userWindow *userwindow = new userWindow(user);
    userwindow->show();
    this->close();
}
void phraseWindow::openSetting()
{
    moreWindow *morewindow = new moreWindow(user);
    morewindow->show();
    this->close();
}
