#include "userwindow.h"

userWindow::userWindow()
{
    this->resize(270, 400);
    this->setWindowFlags(Qt::FramelessWindowHint);
    usernameLabel.setParent(this);
    usernameLabel.setGeometry(0, 0, this->width(), 300);
    usernameLabel.setText("这里是用户头像和用户名称");
    usernameLabel.setAlignment(Qt::AlignCenter);
    newWordButton.setParent(this);
    newWordButton.setGeometry(this->width()-150,90, 130, 30);
    newWordButton.setText("我的生词本管理");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    learningTime.setText("    登录时间");
    haveRecited.setText("    已经学习了_____个单词");
    currentBook.setText("    当前词书");
    currentWordNumber.setText("    当前词汇量");
    mainLayout->addWidget(&usernameLabel);
    mainLayout->addWidget(&learningTime);
    mainLayout->addWidget(&haveRecited);
    mainLayout->addWidget(&currentBook);
    mainLayout->addWidget(&currentWordNumber);

    mainLayout->setGeometry(QRect(0, 80, this->width(), 200));
    mainLayout->setSpacing(0);
    mainLayout->setStretch(0, 2);
    mainLayout->setStretch(1, 1);
    mainLayout->setStretch(2, 1);
    mainLayout->setStretch(3, 1);
    mainLayout->setStretch(4, 1);
    this->setLayout(mainLayout);

}

userWindow::~userWindow()
{

}

