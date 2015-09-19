#include "mainwindow.h"
mainWindow::mainWindow(User *user):user(user)
{
    this->resize(270, 480);
    setWindowFlags(Qt::FramelessWindowHint);
    background.setParent(this);
    background.setStyleSheet("background:url(:/image/mainWIndow.jpg)");
    background.setGeometry(0, 0, this->width(), this->height());
    //单词解释
    searchWordEdit.setParent(this);
    searchWordEdit.setGeometry(70, 5, 130, 25);
    meaningLabel.setParent(this);
    meaningLabel.setGeometry(88, 38, 150, 20);
    meaningLabel.setStyleSheet("background-color:transparent");
    //浮动窗口
    remindLabel.setParent(this);
    remindLabel.setGeometry(30, 70, 210, 40);
    remindLabel.setText("这里会显示一些浮动信息");
    remindLabel.setAlignment(Qt::AlignCenter);
    //已完成，未完成

    //两个并排 今天学习， 待复习
    //学习 复习 生词本
    learn.setParent(this);
    review.setParent(this);
    noteWordLearning.setParent(this);
    learn.setGeometry(13, 371, 70, 40);
    learn.setStyleSheet("background-color:transparent");
    review.setGeometry(85, 369, 72, 40);
    review.setStyleSheet("background-color:transparent");
    noteWordLearning.setGeometry(160, 370, 95, 40);
    noteWordLearning.setStyleSheet("background-color:transparent");
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
//    more.setText("更多");

    connect(&phrase, SIGNAL(clicked()), this, SLOT(openPhraseLearning()));
    connect(&translateButton, SIGNAL(clicked()), this, SLOT(openTranslate()));
    connect(&aboutUser, SIGNAL(clicked()), this, SLOT(openUser()));
    connect(&more, SIGNAL(clicked()), this, SLOT(openSetting()));
    connect(&learn, SIGNAL(clicked()), this, SLOT(startLearning()));
    connect(&noteWordLearning, SIGNAL(clicked()), this, SLOT(startLearningNew()));
    connect(&review, SIGNAL(clicked()), this, SLOT(startReview()));
}

mainWindow::~mainWindow()
{

}
//private slots
void mainWindow::startReview()
{
    WORD word = {"spell", "translation", "label", "englishMeaning"
                 ,"example", "exampleMeaninglonglonglong"};

    singleWord *window = new singleWord(word, this);
    window->show();
}

void mainWindow::startLearningNew()
{
    singleNewword *window = new singleNewword();
    window->show();
    this->close();
}

void mainWindow::startLearning()
{
    WORD word = {"spell", "translation", "label", "englishMeaning"
                 ,"example", "exampleMeaninglonglonglong"};

    singleWord *window = new singleWord(word, this);
    window->show();
}

void mainWindow::openTranslate()
{
    translateWindow *translatewindow = new translateWindow(user);
    translatewindow->show();
    this->close();
}

void mainWindow::openPhraseLearning()
{
    phraseWindow *phrasewindow = new phraseWindow(user);
    phrasewindow->show();
    this->close();
}
void mainWindow::openUser()
{
    userWindow *userwindow = new userWindow(user);
    userwindow->show();
    this->close();
}
void mainWindow::openSetting()
{
    moreWindow *morewindow = new moreWindow(user);
    morewindow->show();
    this->close();
}
//protected
void mainWindow::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void mainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();

    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void mainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();
    move(x()+dx, y()+dy);
}

