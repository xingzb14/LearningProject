#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H
#include <QComboBox>
#include "loginWindow.h"
#include "registerwindow.h"

class registerWindow:public QMainWindow
{
    Q_OBJECT
public:
    registerWindow(QWidget *window);
    ~registerWindow();
private:
    QLabel *background;
    QPushButton backButton;
    QLabel topLabel;
    QLineEdit usernameEdit;          //编辑
    QLabel confLabel;
    QPushButton confButton;
    QLineEdit pswdEdit;
    QLineEdit pswdEditConf;          //确认密码
    QLabel wordNumberLabel;          //词汇量
    QComboBox wordNumberBox;
    QPushButton registerButton;
    bool isDifferent;
    QLabel remindLabel;
    QPoint last;
public:                             //接口
    QString getUsername()   { return usernameEdit.text(); }
    QString getPassword()    { return pswdEdit.text(); }
    QString getPasswordConf()   { return pswdEditConf.text(); }

signals:
    void usernameError();            //用户名错误
    void usernameRepeat();           //用户名重复
    void pswdConf();                 //密码确认
    void success();                  //注册成功
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private slots:
    void check();
};

#endif // REGISTERWINDOW_H
