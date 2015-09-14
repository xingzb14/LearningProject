#include "registerwindow.h"
registerWindow::registerWindow(loginWindow *window)
{
    isDifferent = true;
//    isDifferent = false;
    this->resize(270, 480);
    background = new QLabel(this);
    background->setGeometry(0, 0, this->width(), this->height());
    background->setStyleSheet("background:url(:/image/registerwindow.jpg)");
    setWindowFlags(Qt::FramelessWindowHint);

    backButton.setParent(this);
    backButton.setGeometry(8, 6, 44, 16);
//    backButton.setText("back");
    backButton.setStyleSheet("background-color:transparent");
    usernameEdit.setParent(this);
    usernameEdit.setGeometry(30, 250, 210, 30);
    usernameEdit.setPlaceholderText("在此输入用户名");
    usernameEdit.setAlignment(Qt::AlignCenter);
    usernameEdit.setStyleSheet("background-color:#dfe1f2;border:2px groove gray;border-radius:5px;padding:2px 4px;");


    confLabel.setParent(this);
    confLabel.setGeometry(60, 283, 120,30);
    confLabel.setStyleSheet("background-color:transparent");
    confLabel.setText("确认用户名");
    confLabel.setAlignment(Qt::AlignCenter);

    confButton.setParent(this);
    confButton.setGeometry(180, 285, 60, 30);
    confButton.setText("确认");

    pswdEdit.setParent(this);
    pswdEdit.setGeometry(30, 315, 210, 30);
    pswdEdit.setAlignment(Qt::AlignCenter);
    pswdEdit.setPlaceholderText("在此输入您的密码");
    pswdEdit.setStyleSheet("background-color:#dfe1f2;border:2px groove gray;border-radius:5px;padding:2px 4px;");


    pswdEditConf.setParent(this);
    pswdEditConf.setGeometry(30, 355, 210, 30);
    pswdEditConf.setPlaceholderText("再次确认您的密码");
    pswdEditConf.setAlignment(Qt::AlignCenter);
    pswdEditConf.setStyleSheet("background-color:#dfe1f2;border:2px groove gray;border-radius:5px;padding:2px 4px;");

    registerButton.setParent(this);
    registerButton.setGeometry(60, 424, 150, 40);
    registerButton.setStyleSheet("background-color:transparent");
//    registerButton.setStyleSheet("background-color:#dfe1f2;border:2px groove gray;border-radius:5px;padding:2px 4px;");

    remindLabel.setParent(this);
    remindLabel.setGeometry(40, 393, 190, 25);
    remindLabel.setStyleSheet("background-color:transparent;color:red");
    remindLabel.setAlignment(Qt::AlignCenter);
    connect(&backButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(&backButton, SIGNAL(clicked()), window, SLOT(show()));
    connect(&registerButton, SIGNAL(clicked()), this, SLOT(check()));
    connect(this, SIGNAL(success()), this, SLOT(close()));
    connect(this, SIGNAL(success()), window, SLOT(show()));
}

registerWindow::~registerWindow()
{

}

//private slots
void registerWindow::check()
{
    if(isDifferent)
    {
        if(pswdEdit.text()==pswdEditConf.text())
        {
            if(pswdEdit.text().size()>=8)
            {
                emit success();
                return;
            }
            remindLabel.setText("密码请设置在6位以上！");
        }
        else
        {
            remindLabel.setText("请确认两次输入的密码一致");
        }
    }
    else
    {
       remindLabel.setText("请确认您的用户名尚未被注册!");
    }
}

//protected
void registerWindow::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}
void registerWindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();

    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void registerWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();
    move(x()+dx, y()+dy);
}
