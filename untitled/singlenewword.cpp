#include "singlenewword.h"
OPTION test[3] = {{"apple", "苹果", "香蕉", "梨", "桃子", 0},
 {"banana", "苹果", "香蕉", "梨", "桃子", 1},
{"peach", "苹果", "香蕉", "梨", "桃子", 2}};
const int count = 3;
INFO info = {1,2,3,4};
singleNewword::singleNewword()
{
    this->setMaximumSize(270, 480);
    this->setMinimumSize(270, 480);
    this->setWindowFlags(Qt::FramelessWindowHint);
    background = new QLabel(this);
    background->setStyleSheet("background:url(:/image/newWordLearning.jpg)");
    background->setGeometry(0, 0, this->width(), this->height());
    spellLabel = new QLabel(this);
    spellLabel->setGeometry(16, 47, 238, 113);
    spellLabel->setAlignment(Qt::AlignCenter);
    spellLabel->setStyleSheet("font-size:40px");
    optionsA = new QRadioButton(this);
    optionsB = new QRadioButton(this);
    optionsC = new QRadioButton(this);
    optionsD = new QRadioButton(this);
    optionsA->setGeometry(60, 200, 200, 30);
    optionsB->setGeometry(60, 250, 200, 30);
    optionsC->setGeometry(60, 300, 200, 30);
    optionsD->setGeometry(60, 350, 200, 30);
    optionsA->setStyleSheet("font-size:15px");
    optionsB->setStyleSheet("font-size:15px");
    optionsC->setStyleSheet("font-size:15px");
    optionsD->setStyleSheet("font-size:15px");
    nextButton = new QPushButton(this);
    nextButton->setGeometry(68, 418, 127, 44);
    nextButton->setStyleSheet("background-color:transparent");
    remindLabel = new QLabel(this);
//    remindLabel->setStyleSheet("background-color:white");
    remindLabel->setGeometry(30, 133, 210, 23);
    remindLabel->setAlignment(Qt::AlignCenter);
    backButton = new QPushButton(this);
    backButton->setGeometry(10, 7, 39, 17);
    backButton->setStyleSheet("background-color:transparent");
    setInfo(test[0]);
    connect(nextButton, SIGNAL(clicked()), this, SLOT(nextWord()));
    connect(backButton, SIGNAL(clicked()), this, SLOT(back()));
    nowindex = 0;

}

void singleNewword::back()
{
    mainWindow *window = new mainWindow();
    window->show();
    this->close();
}

//private slots
void singleNewword::setInfo(OPTION option)
{

    spellLabel->setText(option.spell);
    optionsA->setText(option.A);

    optionsB->setText(option.B);
    optionsC->setText(option.C);
    optionsD->setText(option.D);
    remindLabel->setStyleSheet("color:black");
    remindLabel->clear();

}

void singleNewword::nextWord()
{
    int theAnswer = getRadioIndex();
    qDebug() << theAnswer;
    if(nowindex < count)
    {
        if(theAnswer==test[nowindex].index)
        {
            remindLabel->setText("选择正确");
            QTime dietime = QTime::currentTime().addSecs(1);    //延迟一秒
            while(QTime::currentTime()<dietime)
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            if(nowindex == count-1)
            {
                newWordSuccess *window = new newWordSuccess(info);
                window->show();
                this->close();
            }
            else
            {
                setInfo(test[nowindex+1]);
            }

        }
        else
        {
            remindLabel->setStyleSheet("color:red");
            remindLabel->setText("选择错误");
            QTime dietime = QTime::currentTime().addSecs(2);    //延迟两秒
            while(QTime::currentTime()<dietime)
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            if(nowindex == count-1)
            {
                newWordSuccess *window = new newWordSuccess(info);
                window->show();
                this->close();
            }
            else
            {
                qDebug() << "hello";

                setInfo(test[nowindex+1]);
            }
        }
        nowindex++;
    }


}

//public


int singleNewword::getRadioIndex()
{
    if(optionsA->isChecked())
        return 0;
    if(optionsB->isChecked())
        return 1;
    if(optionsC->isChecked())
        return 2;
    if(optionsD->isChecked())
        return 3;
    return -1;
}
singleNewword::~singleNewword()
{

}

