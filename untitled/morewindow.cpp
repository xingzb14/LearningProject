#include "morewindow.h"
using namespace std;

moreWindow::moreWindow(User *user):user(user)
{
    setMaximumSize(270, 480);
    setMinimumSize(270, 480);
    setWindowFlags(Qt::FramelessWindowHint);
    background = new QLabel(this);
    background->setStyleSheet("background:url(:/image/moreWindow.jpg)");
    background->setGeometry(0, 0, this->width(), this->height());
    QStringList bookList, numberList;
    bookList << "日常英语" << "高中词汇" <<" 四级词汇" << "六级词汇" << "托福词汇" << "雅思词汇" << "GRE词汇" << "更多";
    numberList << "20" << "30" << "50" << "80" << "100" << "120" << "150" << "200" << "250" << "300";
    BookBox = new QComboBox(this);
    NumberBox = new QComboBox(this);
    BookBox->addItems(bookList);
    NumberBox->addItems(numberList);
    BookBox->setGeometry(30, 75, 120, 25);
//    BookBox->setStyleSheet("font-size:30");
    NumberBox->setGeometry(30, 155, 120, 25);
//    NumberBox->setStyleSheet("font-size:30");
    settingBook = new QPushButton(this);
    settingNumber = new QPushButton(this);
    logoffButton = new QPushButton(this);
    aboutButton = new QPushButton(this);
    settingBook->setGeometry(195, 77, 57, 23);
    settingBook->setStyleSheet("background-color:transparent");
    settingNumber->setGeometry(195, 154, 57, 22);
    settingNumber->setStyleSheet("background-color:transparent");
    aboutButton->setGeometry(105, 230, 58, 23);
    logoffButton->setGeometry(105, 308, 58, 23);
    aboutButton->setStyleSheet("background-color:transparent");
    logoffButton->setStyleSheet("background-color:transparent");

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
    connect(&aboutUser, SIGNAL(clicked()), this, SLOT(openUser()));
//    connect(&more, SIGNAL(clicked()), this, SLOT(openSetting()));

}
void moreWindow::openWordLearning()
{
    mainWindow *mainwindow = new mainWindow(user);
    mainwindow->show();
    this->close();
}

void moreWindow::openPhraseLearning()
{
    phraseWindow *phrasewindow = new phraseWindow(user);
    phrasewindow->show();
    this->close();
}
void moreWindow::openUser()
{
    userWindow *userwindow = new userWindow(user);
    userwindow->show();
    this->close();
}
void moreWindow::openTranslate()
{
    translateWindow *translatewindow = new translateWindow();
    translatewindow->show();
    this->close();
}


moreWindow::~moreWindow()
{

}

