#include "loginWindow.h"
#include <iostream>
using namespace std;
#include "registerwindow.h"
loginWindow::loginWindow()
{
    this->resize(270, 480);
    setWindowFlags(Qt::FramelessWindowHint);
    backGround.setParent(this);
    backGround.setStyleSheet("background-color:lightblue");
    backGround.setGeometry(0, 0, this->width(), this->height());

    topLabel.setParent(this);
    topLabel.setGeometry(0, 0, this->width(), this->height()/18);
    topLabel.setStyleSheet("background-color:white");
    topLabel.setText("登陆界面");
    topLabel.setAlignment(Qt::AlignCenter);

    usernameEdit.setParent(this);
    usernameEdit.setStyleSheet("background-color:#dfe1f2;border:2px groove gray;border-radius:5px;padding:2px 4px;");
    passwordEdit.setParent(this);
    passwordEdit.setStyleSheet("background-color:#dfe1f2;border:2px groove gray;border-radius:5px;padding:2px 4px;");
    loginButton.setParent(this);
    usernameEdit.setGeometry(30, 200, 210, 40);
    passwordEdit.setGeometry(30, 250, 210, 40);
    usernameEdit.setPlaceholderText("请输入您的用户名");
    usernameEdit.setAlignment(Qt::AlignCenter);
    usernameEdit.setMaxLength(16);
    passwordEdit.setPlaceholderText("请输入您的密码");
    passwordEdit.setAlignment(Qt::AlignCenter);
    passwordEdit.setEchoMode(QLineEdit::Password);
    passwordEdit.setMaxLength(20);

    loginButton.setGeometry(40, 300, 190, 40);
    loginButton.setText("sign in");
    loginButton.setStyleSheet("background-color:white");

    registerButton.setParent(this);
    registerButton.setGeometry(80, 400, 110, 40);
    registerButton.setText("注册");

    connect(&loginButton, SIGNAL(clicked()), this, SLOT(volidate()));
    connect(this, SIGNAL(success()), this, SLOT(showRegisterWindow()));         //这里连错了 应该连过渡界面
    connect(&registerButton, SIGNAL(clicked()), this, SLOT(showRegisterWindow()));

}

loginWindow::~loginWindow()
{

}

//private slots
void loginWindow::showRegisterWindow()
{
    cout << "hello" << endl;
    registerWindow *registerwindow = new registerWindow(this);
    registerwindow->show();
    this->hide();
}
void loginWindow::volidate()
{
    if(usernameEdit.text() == passwordEdit.text())      //实际上应该在数据库中验证
        emit success();
}

//protected
void loginWindow::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void loginWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();

    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void loginWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();
    move(x()+dx, y()+dy);
}
void loginWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_Escape)
        this->close();
    if(e->key()==Qt::Key_Enter)
        loginButton.click();
}

