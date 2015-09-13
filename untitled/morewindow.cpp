#include "morewindow.h"
using namespace std;

moreWindow::moreWindow()
{
    setMaximumSize(270, 480);
    setMinimumSize(270, 480);
    setWindowFlags(Qt::FramelessWindowHint);
    QLabel *background = new QLabel(this);
    background->setStyleSheet("background-color:lightblue");
    background->setGeometry(0, 0, this->width(), this->height());
    toplabel = new QLabel(this);
    toplabel->setGeometry(0, 0, this->width(), this->height()/16);
    toplabel->setStyleSheet("background-color:white");
    toplabel->setText("设置界面");
    toplabel->setAlignment(Qt::AlignCenter);
    QVBoxLayout *mainlayout = new QVBoxLayout();
    settingModel = new QPushButton();
    settingBook = new QLabel();
    logoffButton = new QPushButton();
    aboutButton = new QPushButton();
    BookBox = new QComboBox();
    settingModel->setText("夜间模式");
    settingBook->setText("请选择单词等级");
    QStringList bookList;
    bookList << "日常英语" << "高中词汇" <<" 四级词汇" << "六级词汇" << "托福词汇" << "雅思词汇" << "GRE词汇" << "更多";
    BookBox->addItems(bookList);
    QHBoxLayout *hlayout = new QHBoxLayout();
    hlayout->addWidget(settingBook);
    hlayout->addWidget(BookBox);
    logoffButton->setText("注销/切换用户");
    aboutButton->setText("更多信息");
    QLabel *bottomlabel = new QLabel(this);
    bottomlabel->setGeometry(0, this->height()-30, this->width(), 30);
    bottomlabel->setStyleSheet("background-color:white");
    bottomlabel->setText("这里是底部");
    bottomlabel->setAlignment(Qt::AlignCenter);
    mainlayout->addWidget(settingModel);
    mainlayout->addLayout(hlayout);
    mainlayout->addWidget(logoffButton);
    mainlayout->addWidget(aboutButton);
    mainlayout->insertSpacing(0, 30);
    mainlayout->insertSpacing(3, 200);
    mainlayout->insertSpacing(6, 60);

    this->setLayout(mainlayout);

}

moreWindow::~moreWindow()
{

}

