#ifndef NEWWORD_H
#define NEWWORD_H
#include <string>
#include <QString>
#include "QList"

struct newwords
{
    QString Chinese;
    QString English;
    QString Level;
    QString Name;
};

class newword
{
public:
    newword();
    bool add(QString English,QString Chinese,QString Level,QString Name);
    bool remove(QString English ,QString Chinese);
    bool changeMaster(QString English,QString Chinese);
    bool show(QString Name);
    int countnewword(QString Name);
    bool test(QString Name);
public:
    QString Chinese;
    QString English;
    QString Level;
    QString Name;
    QString time;
    int Master;//初始值为0，对一次减一，错一次加一，值达到-2则删除,到2则永不删除
    QList<newwords>w1;//显示生词时访问这个list得到数据
    QList<newwords>w2;
    QList<newwords>w3;//测试时运行test函数之后，访问这个list得到数据
};



#endif // NEWWORD_H
