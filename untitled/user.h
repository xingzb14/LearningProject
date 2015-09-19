#ifndef USER_H
#define USER_H
#include <QString>
#include <QVector>
#include <QDateTime>
#include <QTime>
#include "data.h"
#include "words.h"
#include "phrase.h"
#include "newword.h"
/******************************************************
 * User类
 * 需要存储的信息
 * 用户名、密码
 * 用户的英语书
 * 用户是第几次登录, 登录了几天
 * 单词 词组 生词进度
 *
 *方法：判断用户名是否重复
 *
 * 把类看成一个较大的表 里面存储很多信息进行很多操作
 *
 * 登录界面不写入，注册界面不写入
 * 用户对象每次调用,只需要输入用户名
 * ****************************************************/
class User
{

public:
    User(QString username, bool rememberPassword);
    User() {}
    ~User();
private:
    static int ID;
    QString username;       //用户名
    QString password;       //密码
    BOOK book;              //当前生词书
    int loginTimes;          //登录次数,实际就是size
    int loginDay;           //登录天数
    QString registerTime;   //注册时间(只写入表中)
    //关于单词
    words *myWord;         //单词类
    int totalnum;       //学习过的单词数量
    int needToLearn;    //当前词库尚未学过的
    int todayTotal;     //今天学习过的
    int todayReview;    //今天待复习个数
    //关于生词
    newword *myNewWord;      //生词类
    int numberOfNew;       //生词本总个数
    //关于词组 短语不分级
    phrase *myPhrase;       //词组类
    int phraseTotalNum;     //学过短语的数量
    int phraseNeedTo;       //总共需要学习的短语
    int phraseTodayTotal;   //今天学过的
    int phraseTodayReview;  //今天待复习的

    //用户信息统计
    QVector<QDateTime> LoginInTime;   //所有的登录时间
    QVector<QString> remind;    //浮动信息
    //设置相关
    QString frequency;     //学习频率
    int deleteNum; //去掉生词需要的次数
    bool rememberPassword;  //是否记住密码

public:
    void addDateTime(QDateTime datetime);   //添加日期
    void update();  //计算登陆天数
    bool init();
    bool isCompleted();         //信息是否完成
    bool insertDatabase();      //存入数据库
    void setBook(QString string); //设置单词书
    BOOK getBook()   { return book; } //获取单词数信息
    //注册部分
    bool isRepeated();          //判断用户名是否重复
    bool usernameJudge();       //判断用户名是否合乎规范
    bool passwordJudge();       //判断密码是否合乎规范
    void setPassword();         //设置密码
    QString getFrequency();     //获取用户使用频率
    int getLoginTimes() { return loginTimes; }

};

#endif // USER_H
