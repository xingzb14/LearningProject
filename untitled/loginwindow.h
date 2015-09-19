#ifndef loginWindow_H
#define loginWindow_H
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QPoint>
#include <QMouseEvent>
#include <QMessageBox>
#include <QCheckBox>
#include <QString>
#include <QDebug>
#include <iostream>
#include "loginWindow.h"
#include <QCoreApplication>
#include <QPixmap>
#include <QTime>
#include "registerwindow.h"
#include "tranwindow.h"
#include "user.h"
using namespace std;
class loginWindow:public QMainWindow
{
    Q_OBJECT
public:
    loginWindow();
    ~loginWindow();
private:
    User *user;
    QLabel backGround;
    QPushButton backButton;
    QPushButton loginButton;
    QLineEdit usernameEdit;
    QLineEdit passwordEdit;
    QPushButton registerButton;
    QLabel remindLabel;
    QCheckBox *box;
    QPoint last;
public:        //接口
    QString getUserName() { return usernameEdit.text(); } //获取用户名
    bool isRemember() { return box->checkState();}     //获取是否记住密码的布尔值
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
signals:
    void success();                     //登录成功
private slots:
    void showRegisterWindow();          //打开注册界面
    void volidate();    //验证密码
    void showTranWindow();
    void showdebug()
    {
        qDebug() << getUserName();
    }
};

#endif // loginWindow_H
