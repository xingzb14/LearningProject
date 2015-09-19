#include "words.h"
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
words::words()
{
}

bool words::searchE2C(QString English)//在点击查找（英查中）时调用这个函数，需要把文本框中得到的英文传个这个函数
{
    QSqlDatabase db=createConnection();
    if(!db.isValid())return false;
    QSqlQuery sql2(db);
    sql2.exec("select spelling,translateE,translateC,Level,example,exampleC,note from words where spelling='"+English+"'");
    if(sql2.next())//传回true时直接访问类中的数据成员获得相应数据
    {
       Spelling= sql2.value(0).toString();
       translateE= sql2.value(1).toString();
       translateC= sql2.value(2).toString();
       Level= sql2.value(3).toString();
       example= sql2.value(4).toString();
       exampleC= sql2.value(5).toString();
       note= sql2.value(6).toString();
       return true;
    }
    else{return false;}//传回false时显示没查到相应的单词
}

bool words::showyourwords(QString Level,int number)//用户点击开始背单词时调用这个函数，并且把用户选择的Level传给这个函数,并且把用户选择的背单词数传给这段函数
{
    QSqlDatabase db=createConnection();
    if(!db.isValid())return false;
    QSqlQuery sql7(db);
    sql7.exec("select Spelling,translateE,translateC,Level,example,exampleC,note from words where Level='"+Level+"'and note ='unlearned' and time ='unsure'");//只调用没学过的
    mywords w;
    int t=number;
    int c=0;
    while(sql7.next())
    {
        w.Spelling=sql7.value(0).toString();
        w.translateE=sql7.value(1).toString();
        w.translateC=sql7.value(2).toString();
        w.Level=sql7.value(3).toString();
        w.example=sql7.value(4).toString();
        w.exampleC=sql7.value(5).toString();
        w.note=sql7.value(6).toString();
        w1.append(w);
        QDateTime time;
        QString a=time.currentDateTime().toString("yyyy-MM-dd");
        sql7.exec("update words set time = '"+a+"' where Spelling='"+w.Spelling+"'");
        c=c+1;
        if(c>t)
        {
            break;
        }
    }
    return true;
}

bool words::doget(QString Spelling)//用户点击“学会了”则调用这个函数，需要把当前显示的英文内容发给这个函数
{
    QSqlDatabase db=createConnection();
    if(!db.isValid())return false;
    QSqlQuery sql8(db);
    sql8.exec("update words set note='learned' where Spelling='"+Spelling+"'");
    return true;
}

bool words::notget(QString Spelling)//用户点击“没学会”则调用这个函数，需要把当前显示的英文内容发给这个函数
{
    QSqlDatabase db=createConnection();
    if(!db.isValid())return false;
    QSqlQuery sql13(db);
    sql13.exec("update words set time='unsure' where Spelling='"+Spelling+"'");
    return true;
}

int words::countlearned(QString Level)//统计所有单词学过没学过（分学会和没学会）的时候要调用这个函数，需要用户选择的等级
{
    QSqlDatabase db=createConnection();
    if(!db.isValid())return 0;
    QSqlQuery sql9(db);
    sql9.exec("select Spelling from words where Level='"+Level+"'and note ='learned'");
    int a=sql9.size();
    sql9.exec("select Spelling from words where Level='"+Level+"'");
    int b=sql9.size();
    countunlearnedword=b-a;//在类中访问这个数据成员，获得没学会的单词个数
    return a;//返回已经学会的单词个数
}

bool words::addnewword(QString Spelling,QString Name)//用户点击“添加到生词本”则调用这个函数，需要把当前显示的英文内容和用户名字发给这个函数
{
    QSqlDatabase db=createConnection();
    if(!db.isValid())return false;
    QSqlQuery sql12(db);
    sql12.exec("select Spelling ,translateC , Level from words where Spelling='"+Spelling+"'");
    while(sql12.next())
    {
        Spelling=sql12.value(0).toString();
        translateC=sql12.value(1).toString();
        Level=sql12.value(2).toString();
    }
    QDateTime time;
    QString d=time.currentDateTime().toString("yyyy-MM-dd");
    QString strtmp;
    strtmp="insert into newword(English,Chinese,Master,Level,Name,time) values('"+Spelling+"','"+translateC+"',"+"0"+",'"+Level+"','"+Name+"','"+d+"')";
    sql12.exec(strtmp);//不需要你接受值，数据库内部操作
    return true;
}

bool words::reviewword(QString Level)//用户点击单词复习的时候调用这个函数，需要用户选择的等级
{
    QSqlDatabase db=createConnection();
    if(!db.isValid())return false;
    QSqlQuery sql7(db);
    sql7.exec("select Spelling,translateE,translateC,Level,example,exampleC,note from words where Level='"+Level+"'and note ='learned' and review='not'");
    mywords w;
    int t=10;//内部确定复习个数
    int c=0;
    while(sql7.next())//将所需数据存入w2中
    {
        w.Spelling=sql7.value(0).toString();
        w.translateE=sql7.value(1).toString();
        w.translateC=sql7.value(2).toString();
        w.Level=sql7.value(3).toString();
        w.example=sql7.value(4).toString();
        w.exampleC=sql7.value(5).toString();
        w.note=sql7.value(6).toString();
        w2.append(w);//直接访问w2得到复习单词数据
        sql7.exec("update words set review='yes' where Spelling='"+w.Spelling+"'");
        c=c+1;
        if(c>t)
        {
            break;
        }
    }
    return true;
}
