#include "newword.h"
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include "CONNECTION.h"
#include <QVariant>
#include <iostream>
#include <stdio.h>
#include <QDebug>
#include <QApplication>
#include <QTextStream>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlError>
#include <string>
#include <QString>
#include <QDateTime>
#include <QList>

newword::newword()
{
}

bool newword::add(QString English,QString Chinese,QString Level,QString Name)//用户直接添加生词，将从文本框中获取的信息传给这个函数。
{
    QSqlDatabase db=createConnection();
    if(!db.isValid())return false;
    QSqlQuery sql3(db);
    QString strtmp;
    strtmp="select English, Chinese, Level, Name from newword where English='"+English+"'";
    sql3.exec(strtmp);
    if(sql3.size()==0)
    {
        return false;
    }
    else
    {
        QDateTime time;
        QString a=time.currentDateTime().toString("yyyy-MM-dd");
        strtmp="insert into newword(English,Chinese,Master,Level,Name,time) values('"+English+"','"+Chinese+"',"+"0"+",'"+Level+"','"+Name+"','"+a+"')";
        sql3.exec(strtmp);
        db.close();
        return true;
    }
}

bool newword::changeMaster(QString English,QString Chinese)//在生词测试部分，将英文和用户选择的中文传给这个函数
{
    QSqlDatabase db=createConnection();
    if(!db.isValid())return false;
    QSqlQuery sql4(db);
    sql4.exec("select Master from newword where Chinese='"+Chinese+"' and English='"+English+"'");
    int a=0;
    if(sql4.size()==0)//选错了
    {
        sql4.exec("select Master from newword where English='"+English+"'");//找到英文对应的单词的Master
        a=sql4.value(0).toInt();
        a=a+1;
        if(a>2)
        {
            a=2;
        }
        QString s=QString::number(a,10);
        sql4.exec("update newword set Master='"+s+"'where English='"+English+"'");//改变对应的Master值
    }
    else//选对了
    {
        sql4.exec("select Master from newword where English='"+English+"'");
        a=sql4.value(0).toInt();
        if(a>=2)
        {
            return false;
        }
        else
        {
            a=a-1;
            if(a<=-2)
            {
                sql4.exec("delete from newword where English='"+English+"'");
                return true;//如果该单词被删除，则返回给你一个true其他情况全部返回false
            }
            else
            {
                QString s=QString::number(a,10);
                sql4.exec("update newword set Master='"+s+"'where English='"+English+"'");
            }
        }
    }
    return false;
}

bool newword::remove(QString English,QString Chinese)//用户在生词表中直接删除调用该函数，传给该函数删除单词对应的中文和英文
{
    QSqlDatabase db=createConnection();
    if(!db.isValid())return false;
    QSqlQuery sql5(db);
    sql5.exec("delete from newword where Chinese='"+Chinese+"' and English='"+English+"'");
    return true;
}

bool newword::show(QString Name)//用户调出生词本本时显示生词，应该在用户点击生词本时调用该函数，把用户名字传给该函数
{
    QSqlDatabase db=createConnection();
    if(!db.isValid())return false;
    QSqlQuery sql6(db);
    sql6.exec("select English,Chinese,Level,Name from newword where Name='"+Name+"'");
    newwords w;
    while(sql6.next())
    {
        w.English=sql6.value(0).toString();
        w.Chinese=sql6.value(1).toString();
        w.Level=sql6.value(3).toString();
        w.Name=sql6.value(4).toString();
        w1.append(w);//最后可以直接在class的public里面访问这个list的数据
    }
    return true;
}

int newword::countnewword(QString Name)//可以统计生词本中生词的个数，需要用户的名字
{
    QSqlDatabase db=createConnection();
    if(!db.isValid())return 0;
    QSqlQuery sql10(db);
    sql10.exec("select English from words where Name='"+Name+"'");
    int a=sql10.size();
    return a;
}

bool newword::test(QString Name)//生词测试时调用，需要用户的名字，输出5个单词及正确答案，存在w3这个List中，可以直接访问w3获得数据
{
    QSqlDatabase db=createConnection();
    if(!db.isValid())return false;
    QSqlQuery sql11(db);
    sql11.exec("select English,Chinese,Level,Name from newword where Name='"+Name+"'");
    int a=sql11.size();
    newwords w,k;
    while(sql11.next())
    {
        w.English=sql11.value(0).toString();
        w.Chinese=sql11.value(1).toString();
        w.Level=sql11.value(3).toString();
        w.Name=sql11.value(4).toString();
        w2.append(w);//不要访问这个list
    }
    int h=0;
    int q[5]={-1,-1,-1,-1,-1};
    for(int i=0;i<5;i++)//随即抽取+排重
    {
        int n=rand()%a;
        if(n==q[0]&&n==q[1]&&n==q[2]&&n==q[3]&&n==q[4])
        {
            i=i-1;
        }
        else
        {
            q[h]=n;
            h=h+1;
        }
    }
    for(int i=0;i<5;i++)
    {
        k.English=w2.at(q[i]).English;
        k.Chinese=w2.at(q[i]).Chinese;
        k.Level=w2.at(q[i]).Level;
        k.Name=w2.at(q[i]).Name;
        w3.append(k);
    }
    return true;
}
