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





class loginWindow:public QMainWindow
{
    Q_OBJECT
public:
    loginWindow();
    ~loginWindow();
private:
    QLabel backGround;
    QPushButton backButton;
    QPushButton loginButton;
    QLineEdit usernameEdit;
    QLineEdit passwordEdit;
    QPushButton registerButton;
    QLabel remindLabel;
    QPoint last;
//    registerWindow registerwindow;      //注册界面
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
};

#endif // loginWindow_H
