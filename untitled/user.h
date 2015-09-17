#ifndef USER_H
#define USER_H
#include <QString>
/******************************************************
 * User类
 * 需要存储的信息
 * 用户名、密码
 * 用户的英语书
 * 用户是第几次登录, 登录了几天
 *
 *
 *
 *
 *
 *
 *
 *
 * ****************************************************/
class User
{
public:
    User();
    ~User();
private:
    QString username;
    QString password;


};

#endif // USER_H
