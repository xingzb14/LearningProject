#ifndef WORDS_H
#define WORDS_H
#include <string>
#include <QString>
#include <QList>

using namespace std;

struct mywords
{
    QString Spelling;
    QString translateE;
    QString translateC;
    QString Level;
    QString example;
    QString exampleC;
    QString note;
};

class words
{
public:
    words();
    bool searchE2C(QString English);
    bool showyourwords(QString Level,int number);
    bool doget(QString Spelling);
    bool notget(QString Spelling);
    int countlearned(QString Level);
    bool addnewword(QString Spelling,QString Name);
    bool reviewword(QString Level);
public:
    QString Spelling;
    QString translateE;
    QString translateC;
    QString Level;
    QString example;
    QString exampleC;
    QString note;
    QString time;
    int countunlearnedword;
    QList<mywords>w1;
    QList<mywords>w2;
};


#endif // WORDS_H
