#include "learningwindow.h"

learningWindow::learningWindow()
{
    resize(270, 480);
    setMaximumSize(270, 480);
    setMinimumSize(270, 480);
    setWindowFlags(Qt::FramelessWindowHint);
    QLabel *background = new QLabel(this);
    background->setStyleSheet("background-color:lightblue");
    background->setGeometry(0, 0, this->width(), this->height());
    toplabel = new QLabel(this);
    toplabel->setGeometry(0, 0, this->width(), this->height()/16);
    toplabel->setText("单词学习部分");
    toplabel->setAlignment(Qt::AlignCenter);
    toplabel->setStyleSheet("background-color:white");
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QSpacerItem *topItem = new QSpacerItem(this->width(), 30);
    mainLayout->addSpacerItem(topItem);

    backbutton = new QPushButton(this);
    backbutton->setGeometry(5, 5, 60, 20);
    backbutton->setText("back");
    wordLabel = new QLabel();
    wordmeaning = new QLabel();
    sentenceLabel = new QLabel();
    noteEdit = new QTextEdit();
    mainLayout->addWidget(wordLabel);
    wordLabel->setText("这里显示单词");
    mainLayout->addWidget(wordmeaning);
    wordmeaning->setText("这里显示释义");
    mainLayout->addWidget(sentenceLabel);
    sentenceLabel->setText("这里是例句");
    mainLayout->addWidget(noteEdit);
    QHBoxLayout *hlayout = new QHBoxLayout();
    preButton = new QPushButton();
    nextButton = new QPushButton();
    preButton->setText("上一个");
    nextButton->setText("下一个");
    hlayout->addWidget(preButton);
    hlayout->addWidget(nextButton);
    hlayout->setSpacing(30);
    mainLayout->addLayout(hlayout);
    mainLayout->setStretch(0, 3);
    mainLayout->setStretch(1, 4);
    mainLayout->setStretch(2, 4);
    mainLayout->setStretch(3, 1);
    this->setLayout(mainLayout);

}

learningWindow::~learningWindow()
{

}

