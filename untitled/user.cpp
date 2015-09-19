#include "user.h"
int User::ID = 0;
User::User(QString usernam, bool rememberPassword)
{
    this->username = username;
    init();
    this->rememberPassword = rememberPassword;
}
void User::addDateTime(QDateTime datetime)
{
    LoginInTime.push_front(datetime);
}

bool User::init()
{
    //判断
    //从数据库中获取所有信息
}

bool User::isCompleted()       //是否注册成功
{
    return true;
}
bool User::isRepeated()
{
    return false;
}
void User::update() //计算登录天数
{
    if(LoginInTime.size()<=1)
        loginTimes = LoginInTime.size();
    else
    {
        for(int i=0; i<LoginInTime.size(); i++)
        {
            for(int j=0; j<i; j++)
            {
                if(LoginInTime[i].daysTo(LoginInTime[j])!=0)
                {
                    loginTimes++;
                }
            }
        }
    }
}

bool User::usernameJudge()
{
    if(username[0]>'z' || username[0]<'a')
        return false;
    for(int i=0; i<username.size(); i++)
    {
        if(!(username[i]<='z'&&username[i]>='z'&&username[i]<='9' &&username[i]>='0'))
            return false;
    }
    return true;
}

void User::setBook(QString string)
{
    if(string=="DAILY")
        book = DAILY;
    if(string=="HIGHSCHOOL")
        book = HIGHSCHOOL;
    if(string=="CET_4")
        book = CET_4;
    if(string=="CET_6")
        book = CET_6;
    if(string=="TOEFL")
        book = TOEFL;
    if(string=="GRE")
        book = DAILY;
    if(string=="MORE")
        book = MORE;
    if(string=="DEFAULT")
        book = DEFAULT;
}
QString User::getFrequency()
{
    int count = 0;
    QDateTime now = QDateTime::currentDateTime();
    for(int i=0; i<LoginInTime.size(); i++)
    {
        if(LoginInTime[i].daysTo(now)<2)
            count++;
    }
    if(count>5)
    {
        return "高";
    }
    else if(count>2)
        return "中";
    else
        return "低";
}


//bool User::insertDatabase()
//{
//    //存入数据库
        //包括各种数据
//}



























User::~User()
{

}


