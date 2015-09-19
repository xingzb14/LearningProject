#include "phrase.h"
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
phrase::phrase()
{
}

bool phrase::doget(QString English)//在词组学习界面点击“记住了”调用这个函数，需要传给这个函数现在显示的英文
{
    QSqlDatabase db=createConnection();
    if(!db.isValid())return false;
    QSqlQuery sql14(db);
    sql14.exec("update phrase set note='learned' where English='"+English+"'");
    return true;
}

bool phrase::notget(QString English)//在词组学习界面点击“没记住”，调用这个函数，需要传给这个函数现在显示的英文
{
        QSqlDatabase db=createConnection();
        if(!db.isValid())return false;
        QSqlQuery sql15(db);
        sql15.exec("update phrase set time='unsure' where English='"+English+"'");//将时间归0方便下次调用
        return true;
}

bool phrase::showyourphrase(int number)//当用户点击词组学习的时候调用这个函数，提供用户选择的个数
{
    QSqlDatabase db=createConnection();
    if(!db.isValid())return false;
    QSqlQuery sql16(db);
    sql16.exec("select Chinese,English from phrase where note ='unlearned' and time ='unsure'");
    myphrase q;
    int t=number;
    int c=0;
    while(sql16.next())
    {
        q.English=sql16.value(0).toString();
        q.Chinese=sql16.value(1).toString();
        q1.append(q);//直接访问这个list得到需要的数据
        QDateTime time;
        QString a=time.currentDateTime().toString("yyyy-MM-dd");
        sql16.exec("update words set time = '"+a+"' where English='"+q.English+"'");
        c=c+1;
        if(c>t)//保证传给你的词组个数是用户要求的个数
        {
            break;
        }
    }
    return true;
}

bool phrase::reviewphrase()//当用户点击词组复习的时候调用这个函数
{
    QSqlDatabase db=createConnection();
    if(!db.isValid())return false;
    QSqlQuery sql7(db);
    sql7.exec("select English,Chinese,note,time from phrase where note ='learned' and review ='not'");
    myphrase q;
    int t=10;//可以修改这个复习词组个数的值（最好我们给定，不要用户修改）
    int c=0;
    while(sql7.next())
    {
        q.English=sql7.value(0).toString();
        q.Chinese=sql7.value(1).toString();
        q.note=sql7.value(2).toString();
        q.time=sql7.value(3).toString();
        q2.append(q);
        sql7.exec("update phrase set review='yes' where English='"+q.English+"'");
        c=c+1;
        if(c>t)
        {
            break;
        }
    }
    return true;
}
