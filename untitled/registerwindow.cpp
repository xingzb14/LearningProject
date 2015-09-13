#include "registerwindow.h"

registerWindow::registerWindow(loginWindow *window)
{
    isDifferent = true;
//    isDifferent = false;
    this->resize(270, 480);
    background = new QLabel(this);
    background->setGeometry(0, 0, this->width(), this->height());
    background->setStyleSheet("background-color:lightblue");
    setWindowFlags(Qt::FramelessWindowHint);

    topLabel.setParent(this);
    topLabel.setGeometry(0, 0, this->width(), this->height()/18);
    topLabel.setStyleSheet("background-color:white");
    topLabel.setText("注册界面");
    topLabel.setAlignment(Qt::AlignCenter);

    backButton.setParent(this);
    backButton.setGeometry(3, 3, 30, 16);
    backButton.setText("back");
    usernameEdit.setParent(this);
    usernameEdit.setGeometry(30, 200, 210, 40);
    usernameEdit.setPlaceholderText("在此输入用户名");
    usernameEdit.setAlignment(Qt::AlignCenter);

    confLabel.setParent(this);
    confLabel.setGeometry(60, 250, 120,30);
    confLabel.setStyleSheet("background-color:transparent");
    confLabel.setText("确认用户名");
    confLabel.setAlignment(Qt::AlignCenter);

    confButton.setParent(this);
    confButton.setGeometry(180, 250, 60, 30);
    confButton.setText("确认");
    pswdEdit.setParent(this);
    pswdEdit.setGeometry(30, 290, 210, 40);
    pswdEdit.setAlignment(Qt::AlignCenter);
    pswdEdit.setPlaceholderText("在此输入您的密码");

    pswdEditConf.setParent(this);
    pswdEditConf.setGeometry(30, 350, 210, 40);
    pswdEditConf.setPlaceholderText("再次确认您的密码");
    pswdEditConf.setAlignment(Qt::AlignCenter);

    registerButton.setParent(this);
    registerButton.setGeometry(50, 400, 170, 40);
    registerButton.setText("点我注册");

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
            QMessageBox::warning(this, "确认密码", "密码请设置在6位以上！", QMessageBox::Cancel, QMessageBox::Yes);
        }
        else
        {
            QMessageBox::warning(this, "确认密码", "请确认两次输入的密码一致", QMessageBox::Cancel, QMessageBox::Yes);
        }
    }
    else
    {
        QMessageBox::warning(this, "请确认用户名", "请确认您的用户名尚未被注册！",QMessageBox::Cancel,QMessageBox::Yes);
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
