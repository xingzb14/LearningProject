#ifndef SINGLEPHRASE_H
#define SINGLEPHRASE_H
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QVector>
#include "data.h"
#include "phrasesuccess.h"
class singlePhrase:public QWidget
{
    Q_OBJECT
public:
    singlePhrase();
    ~singlePhrase();
private:
    QLabel *background;
    QLabel *phrase1;
    QLabel *phrase2;
    QLabel *phrase3;
    QLabel *trans1;
    QLabel *trans2;
    QLabel *trans3;
    QPushButton *rememberButton;
    QPushButton *notRememberButton;
    QPushButton *backButton;
    QVector<PHRASE> phrase;
    int index;
public:
    bool setInfo(QVector<PHRASE> phrase);


private slots:
    void remember();
    void notRemember();
    void back();
};

#endif // SINGLEPHRASE_H
