#include "phrasesuccess.h"

phraseSuccess::phraseSuccess()
{
    this->resize(270, 480);
    this->setWindowFlags(Qt::FramelessWindowHint);
    background = new QLabel(this);
    background->setStyleSheet("background:url(:/image/phraseSuccess.jpg)");
    background->setGeometry(0, 0, this->width(), this->height());
    backButton = new QPushButton(this);
    backButton->setGeometry(68, 418, 127, 44);
    backButton->setStyleSheet("background-color:transparent");
    topBackButton = new QPushButton(this);
    topBackButton->setGeometry(10, 7, 39, 17);
    topBackButton->setStyleSheet("background-color:transparent");

    connect(backButton, SIGNAL(clicked()), this, SLOT(nextStage()));
    connect(topBackButton, SIGNAL(clicked()), this, SLOT(back()));
}
void phraseSuccess::back()
{
    mainWindow *window = new mainWindow();
    window->show();
    this->close();
}
void phraseSuccess::nextStage()

{
    back();
}

