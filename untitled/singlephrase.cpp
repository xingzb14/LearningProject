#include "singlephrase.h"

singlePhrase::singlePhrase():user(user)
{
    index = 0;
    resize(270, 480);
    setWindowFlags(Qt::FramelessWindowHint);
    background = new QLabel(this);
    background->setStyleSheet("background:url(:/image/phraseTable.jpg)");
    background->setGeometry(0, 0, this->width(), this->height());
    phrase1 = new QLabel(this);
    phrase2 = new QLabel(this);
    phrase3 = new QLabel(this);
    trans1 = new QLabel(this);
    trans2 = new QLabel(this);
    trans3 = new QLabel(this);
    phrase1->setAlignment(Qt::AlignCenter);
    phrase1->setStyleSheet("font-size:20px");
    phrase2->setAlignment(Qt::AlignCenter);
    phrase2->setStyleSheet("font-size:20px");
    phrase3->setAlignment(Qt::AlignCenter);
    phrase3->setStyleSheet("font-size:20px");

    trans1->setAlignment(Qt::AlignCenter);
    trans2->setAlignment(Qt::AlignCenter);
    trans3->setAlignment(Qt::AlignCenter);
    phrase1->setGeometry(35, 60, 200, 60);
    phrase2->setGeometry(35, 177, 200, 60);
    phrase3->setGeometry(35, 294, 200, 60);
    trans1->setGeometry(75, 130, 120, 20);
    trans2->setGeometry(75, 247, 120, 20);
    trans3->setGeometry(75, 364, 120, 20);
    rememberButton = new QPushButton(this);
    notRememberButton = new QPushButton(this);
    rememberButton->setGeometry(28, 417, 112, 40);
    notRememberButton->setGeometry(130, 417, 115, 40);
    rememberButton->setStyleSheet("background-color:transparent");
    notRememberButton->setStyleSheet("background-color:transparent");
    backButton = new QPushButton(this);
    backButton->setGeometry(10, 7, 39, 17);
    backButton->setStyleSheet("background-color:transparent");
    PHRASE ph1 = {"have fun", "开心"};
    PHRASE ph2 = {"good morning", "早上好"};
    PHRASE ph3 = {"no", "不开心"};

    phrase.append(ph1);
    phrase.append(ph2);
    phrase.append(ph3);
    setInfo(phrase);
    connect(rememberButton, SIGNAL(clicked()), this, SLOT(remember()));
    connect(notRememberButton, SIGNAL(clicked()), this, SLOT(notRemember()));
    connect(backButton, SIGNAL(clicked()), this, SLOT(back()));

}
void singlePhrase::back()
{
    phraseWindow *window = new phraseWindow(user);
    window->show();
    this->close();
}

void singlePhrase::remember()
{
    if(!setInfo(phrase))
    {
        phraseSuccess *window = new phraseSuccess(user);
        window->show();
        this->close();
    }
}
void singlePhrase::notRemember()
{
    if(!setInfo(phrase))
    {
        phraseSuccess *window = new phraseSuccess(user);
        window->show();
        this->close();
    }
}


bool singlePhrase::setInfo(QVector<PHRASE> phrase)
{

        int size = phrase.size();
        qDebug() << size << " " << index;
        if(phrase.size()-index==0)
            return false;
        if(phrase.size()-index>=3)
        {
            for(int i=0; i<phrase.size()-index; i++)
            {
                phrase1->setText(phrase[index].spell);
                trans1->setText(phrase[index].meaning);
                index++;
                phrase2->setText(phrase[index].spell);
                trans2->setText(phrase[index].meaning);
                index++;
                phrase3->setText(phrase[index].spell);
                trans3->setText(phrase[index].meaning);
                index++;
            }
            return true;
        }
        if(phrase.size()-index==2)
        {
            for(int i=0; i<phrase.size()-index; i++)
            {
                phrase1->setText(phrase[index].spell);
                trans1->setText(phrase[index].meaning);
                index++;
                phrase2->setText(phrase[index].spell);
                trans2->setText(phrase[index].meaning);
                index++;
                phrase3->clear();
                trans3->clear();

            }
            return true;
        }
        if(phrase.size()-index==1)
        {
            for(int i=0; i<phrase.size()-index; i++)
            {
                phrase1->setText(phrase[index].spell);
                trans1->setText(phrase[index].meaning);
                index++;
                phrase2->clear();
                trans2->clear();
                phrase3->clear();
                trans3->clear();

            }
            return true;
        }

}

singlePhrase::~singlePhrase()
{

}

