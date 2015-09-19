#ifndef PHRASE_H
#define PHRASE_H
#include <string>
#include <QString>
#include "QList"
using namespace std;

struct myphrase
{
    QString Chinese;
    QString English;
    QString note;
    QString time;
};

class phrase
{
public:
    phrase();
    bool doget(QString English);
    bool notget(QString English);
    bool showyourphrase(int number);
    bool reviewphrase();
public:
    QString Chinese;
    QString English;
    QString note;
    QString time;
    QList<myphrase>q1;
    QList<myphrase>q2;
};

#endif // PHRASE_H
