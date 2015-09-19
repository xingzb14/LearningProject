#ifndef SINGLEWORD_H
#define SINGLEWORD_H
#include <QVector>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QString>
#include "data.h"
#include "wordsuccess.h"
class singleWord:public QWidget
{
    Q_OBJECT
public:
    singleWord(WORD word, QWidget *parent, User *user);
private:
    User *user;
    QWidget *parent;
    WORD word;
    QPushButton *backButton;
    QLabel *background;
    QLabel *spellLabel;
    QLabel *translationLabel;
    QLabel *label;
    QLabel *englishMeaningLabel;
    QLabel *exampleLabel;
    QLabel *exampleMeaningLabel;
    QPushButton *notRememberButton;
    QPushButton *addNewWordButton;
    QPushButton *rememberButton;

    int index;
public:
    void setSpell(QString spell) { spellLabel->setText(spell); }
    void setTranslation(QString string) { translationLabel->setText(string); }
    void setLabel(QString string) { label->setText(string); }
    void setEnglishMeaning(QString string) { englishMeaningLabel->setText(string); }
    void setExample(QString string) { exampleLabel->setText(string); }
    void setExampleMeaning(QString string) { exampleMeaningLabel->setText(string); }
    void nextWord(WORD word);    //下一个单词
private slots:
    void remember();    //记住了
    void addNew();      //添加新词
    void notRemember(); //没有记住
    void back();
};

#endif // SINGLEWORD_H
