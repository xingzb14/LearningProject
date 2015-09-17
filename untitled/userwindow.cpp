#include "userwindow.h"
userWindow::userWindow()
{
    this->resize(270, 480);
    this->setWindowFlags(Qt::FramelessWindowHint);
    background.setParent(this);
    background.setStyleSheet("background:url(:/image/userWindow.jpg)");
    background.setGeometry(0, 0, this->width(), this->height());

    usernameLabel.setParent(this);
    learningTime.setParent(this);
    haveWords.setParent(this);
    havePhrases.setParent(this);
    newWordNumber.setParent(this);
    currentBook.setParent(this);
    nowFrequency.setParent(this);
    newWordButton.setParent(this);

    usernameLabel.setGeometry(100, 58, 100, 35);
    usernameLabel.setStyleSheet("background-color:transparent");
    usernameLabel.setText("这里显示昵称");
    newWordButton.setGeometry(70, 120, 128, 40);
    newWordButton.setStyleSheet("background-color:transparent");
    learningTime.setGeometry(135, 176, 130, 30);
    haveWords.setGeometry(135, 216, 130, 30);
    havePhrases.setGeometry(135, 256, 130, 30);
    newWordNumber.setGeometry(135, 296, 130, 30);
    currentBook.setGeometry(135, 336, 130, 30);
    nowFrequency.setGeometry(135 ,376, 130, 30);
    learningTime.setStyleSheet("background-color:transparent");
    haveWords.setStyleSheet("background-color:transparent");
    havePhrases.setStyleSheet("background-color:transparent");
    newWordNumber.setStyleSheet("background-color:transparent");
    currentBook.setStyleSheet("background-color:transparent");
    nowFrequency.setStyleSheet("background-color:transparent");
    usernameLabel.setAlignment(Qt::AlignCenter);
    learningTime.setAlignment(Qt::AlignCenter);
    haveWords.setAlignment(Qt::AlignCenter);
    havePhrases.setAlignment(Qt::AlignCenter);
    newWordNumber.setAlignment(Qt::AlignCenter);
    currentBook.setAlignment(Qt::AlignCenter);
    nowFrequency.setAlignment(Qt::AlignCenter);

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
    connect(&phrase, SIGNAL(clicked()), this, SLOT(openPhraseLearning()));
    connect(&translateButton, SIGNAL(clicked()), this, SLOT(openTranslate()));
//    connect(&aboutUser, SIGNAL(clicked()), this, SLOT(openUser()));
    connect(&more, SIGNAL(clicked()), this, SLOT(openSetting()));

    connect(&newWordButton, SIGNAL(clicked()), this, SLOT(openManage()));



}
//private slots
void userWindow::openTranslate()
{
    translateWindow *translatewindow = new translateWindow();
    translatewindow->show();
    this->close();
}

void userWindow::openPhraseLearning()
{
    phraseWindow *phrasewindow = new phraseWindow();
    phrasewindow->show();
    this->close();
}
void userWindow::openWordLearning()
{
    mainWindow *wordlearning = new mainWindow();
    wordlearning->show();
    this->close();
}
void userWindow::openSetting()
{
    moreWindow *morewindow = new moreWindow();
    morewindow->show();
    this->close();
}
void userWindow::openManage()
{
    newWordManageWindow *managewindow = new newWordManageWindow();
    managewindow->show();
    this->close();
}

userWindow::~userWindow()
{

}

