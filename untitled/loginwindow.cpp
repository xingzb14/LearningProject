#include "loginwindow.h"
using namespace std;

loginWindow::loginWindow()
{
    this->resize(270, 480);
    setWindowFlags(Qt::FramelessWindowHint);



    backGround.setParent(this);
    backGround.setStyleSheet("background:url(:/image/loginwindow.jpg)");
    backGround.setGeometry(0, 0, this->width(), this->height());
    usernameEdit.setParent(this);
    usernameEdit.setStyleSheet("background-color:#dfe1f2;border:2px groove gray;border-radius:5px;padding:2px 4px;");
    passwordEdit.setParent(this);
    passwordEdit.setStyleSheet("background-color:#dfe1f2;border:2px groove gray;border-radius:5px;padding:2px 4px;");
    loginButton.setParent(this);
    usernameEdit.setGeometry(30, 250, 210, 40);
    passwordEdit.setGeometry(30, 300, 210, 40);
    usernameEdit.setPlaceholderText("请输入您的用户名");
    usernameEdit.setAlignment(Qt::AlignCenter);
    usernameEdit.setMaxLength(16);
    passwordEdit.setPlaceholderText("请输入您的密码");
    passwordEdit.setAlignment(Qt::AlignCenter);
    passwordEdit.setEchoMode(QLineEdit::Password);
    passwordEdit.setMaxLength(20);
    box = new QCheckBox(this);
    box->setGeometry(200, 347, 20, 20);


    loginButton.setGeometry(60, 370, 150, 38);
    loginButton.setStyleSheet("background-color:transparent");

    registerButton.setParent(this);
    registerButton.setGeometry(175, 424, 70, 40);
    registerButton.setStyleSheet("background-color:transparent");

    connect(&loginButton, SIGNAL(clicked()), this, SLOT(volidate()));
    connect(this, SIGNAL(success()), this, SLOT(showTranWindow()));         //这里连错了 应该连过渡界面
    connect(&registerButton, SIGNAL(clicked()), this, SLOT(showRegisterWindow()));
//    connect(&loginButton, SIGNAL(clicked()), this, SLOT(showdebug()));
}

loginWindow::~loginWindow()
{

}

//private slots
void loginWindow::showTranWindow()
{
    tranWindow *tranwindow = new tranWindow(this);
    tranwindow->show();
    this->close();

}

void loginWindow::showRegisterWindow()
{
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

