#include "translatewindow.h"

translateWindow::translateWindow(User *user):m_translation("p88oR9EfpmxefbsSjwgRwOxG")
{
    this->user = user;
    this->resize(270, 480);
    this->setWindowFlags(Qt::FramelessWindowHint);
    background.setParent(this);
    background.setStyleSheet("background:url(:/image/translateWindow.jpg)");
    textEdit1.setParent(this);
    textEdit2.setParent(this);
    textEdit1.setGeometry(33, 80, 205, 120);
//    textEdit1.setPlaceholderText("在此输入要翻译的文本");
    textEdit2.setGeometry(33, 275, 205, 120);
//    textEdit2.setPlaceholderText("翻译结果");
    textEdit1.setStyleSheet("background-color:#dfe1f2;border:2px groove gray;border-radius:5px;padding:2px 4px;");
    textEdit2.setStyleSheet("background-color:#dfe1f2;border:2px groove gray;border-radius:5px;padding:2px 4px;");
    translationButton.setParent(this);
    translationButton.setGeometry(175, 212, 55, 20);
    translationButton.setStyleSheet("background-color:transparent");
//    translationButton.setText("翻译");

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
//    more.setText("更多");
    connect(&wordlearning, SIGNAL(clicked()), this, SLOT(openWordLearning()));
    connect(&phrase, SIGNAL(clicked()), this, SLOT(openPhraseLearning()));
//    connect(&translateButton, SIGNAL(clicked()), this, SLOT(openTranslate()));
    connect(&aboutUser, SIGNAL(clicked()), this, SLOT(openUser()));
    connect(&more, SIGNAL(clicked()), this, SLOT(openSetting()));
    connect(&translationButton, SIGNAL(clicked()), this, SLOT(translate()));

}
//private slots
void translateWindow::openWordLearning()
{
    mainWindow *mainwindow = new mainWindow(user);
    mainwindow->show();
    this->close();
}

void translateWindow::openPhraseLearning()
{
    phraseWindow *phrasewindow = new phraseWindow(user);
    phrasewindow->show();
    this->close();
}
void translateWindow::openUser()
{
    userWindow *userwindow = new userWindow(user);
    userwindow->show();
    this->close();
}
void translateWindow::openSetting()
{
    moreWindow *morewindow = new moreWindow(user);
    morewindow->show();
    this->close();
}
void translateWindow::translate()
{
    auto data = m_translation.translation(textEdit1.toPlainText());
    if(data.first)
    {
        textEdit2.setText(data.second);
    }
    else
    {
        textEdit2.setText("Error");
    }
}

translateWindow::~translateWindow()
{

}

