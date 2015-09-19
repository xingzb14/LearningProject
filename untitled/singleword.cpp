#include "singleword.h"

const int count = 4;
singleWord::singleWord(WORD word, QWidget *parent, User *user):user(user), parent(parent)
{
    this->word = word;
    index = 0;
    this->setMaximumSize(270, 480);
    this->setMinimumSize(270, 480);
    this->setWindowFlags(Qt::FramelessWindowHint);
    background = new QLabel(this);
    background->setStyleSheet("background:url(:/image/wordTable.jpg)");
    background->setGeometry(0, 0, this->width(), this->height());
   //一系列现实信息
    backButton = new QPushButton(this);
    backButton->setGeometry(12, 6, 38, 18);
    backButton->setStyleSheet("background-color:transparent");
    spellLabel = new QLabel(this);
    translationLabel = new QLabel(this);
    label = new QLabel(this);
    englishMeaningLabel = new QLabel(this);
    exampleLabel = new QLabel(this);
    exampleMeaningLabel = new QLabel(this);
    spellLabel->setGeometry(35, 60, 200, 60);
    spellLabel->setAlignment(Qt::AlignCenter);
    spellLabel->setStyleSheet("font-size:30px");
    translationLabel->setGeometry(85, 130, 120, 20);
    translationLabel->setAlignment(Qt::AlignCenter);
    translationLabel->setStyleSheet("font-size:20px");
    label->setGeometry(190, 106, 40, 20);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size:15px");
    englishMeaningLabel->setGeometry(80, 168, 135, 50);
    englishMeaningLabel->setAlignment(Qt::AlignCenter);
    englishMeaningLabel->setStyleSheet("font-size:15px");
    exampleLabel->setGeometry(80, 233, 135, 50);
    exampleLabel->setAlignment(Qt::AlignCenter);
    exampleLabel->setStyleSheet("font-size:15px");
    exampleMeaningLabel->setGeometry(80, 305
                                     , 135, 50);
    exampleMeaningLabel->setAlignment(Qt::AlignCenter);
//    exampleMeaningLabel->adjustSize();
    exampleMeaningLabel->setWordWrap(true);
//    exampleMeaningLabel->setAlignment(Qt::AlignTop);

    exampleMeaningLabel->setStyleSheet("font-size:15px");
    setSpell(word.spell);
    setTranslation(word.translation);
    setLabel(word.label);
    setEnglishMeaning(word.englishMeaning);
    setExample(word.example);
    setExampleMeaning(word.exampleMeaning);

    notRememberButton = new QPushButton(this);
    addNewWordButton = new QPushButton(this);
    rememberButton = new QPushButton(this);
    notRememberButton->setGeometry(28, 417, 78, 40);
    notRememberButton->setStyleSheet("background-color:transparent");
    addNewWordButton->setGeometry(96, 417, 81, 40);
    addNewWordButton->setStyleSheet("background-color:transparent");
    rememberButton->setGeometry(168, 417, 79, 40);
    rememberButton->setStyleSheet("background-color:transparent");
    connect(addNewWordButton, SIGNAL(clicked()), this, SLOT(addNew()));
    connect(notRememberButton, SIGNAL(clicked()), this, SLOT(notRemember()));
    connect(rememberButton, SIGNAL(clicked()), this, SLOT(remember()));
    connect(backButton, SIGNAL(clicked()), this, SLOT(back()));

}
WORD list[4] = {{"1", "2", "3", "4", "5", "6"},
                {"2", "3", "4", "5", "6", "7"},
                {"3", "4", "5", "6", "7", "8"},
                {"4", "5", "6", "7", "8", "9"}};
//public
void singleWord::nextWord(WORD word)
{

        setSpell(word.spell);
        setTranslation(word.translation);
        setLabel(word.label);
        setEnglishMeaning(word.englishMeaning);
        setExample(word.example);
        setExampleMeaning(word.exampleMeaning);

}
//slots:
void singleWord::back()
{
    this->close();
    parent->show();
}

void singleWord::remember()
{
    if(index<count)
    {
        nextWord(list[index]);
        index++;
    }
    else
    {
        wordSuccess *window = new wordSuccess(user);
        window->show();
        this->close();
    }
}
void singleWord::addNew()
{
    if(index<count)
    {
        nextWord(list[index]);
        index++;
    }
    else
    {
        wordSuccess *window = new wordSuccess(user);
        window->show();
        this->close();
    }
}
void singleWord::notRemember()
{
    if(index<count)
    {
        nextWord(list[index]);
        index++;
    }
    else
    {
        wordSuccess *window = new wordSuccess(user);
        window->show();
        this->close();
    }
}

