#include "newwordmanagewindow.h"

//int newWordManageWindow::newWordList.size() = 0;
newWordManageWindow::newWordManageWindow(User *user):user(user)
{
    row = 13;
    column = 3;
    currentPage = 1;
    TotalPages = newWordList.size()/row+1;
    this->setMaximumSize(270, 480);
    this->setMinimumSize(270, 480);
    this->setWindowFlags(Qt::FramelessWindowHint);
    background =  new QLabel(this);
    background->setStyleSheet("background:url(:/image/wordManage.jpg)");
    background->setGeometry(0, 0, this->width(), this->height());

    tableWidget = new QTableWidget(row, column);
    tableWidget->setParent(this);
    tableWidget->setGeometry(22, 80, 226, 326);
    QStringList headerList;
    headerList << "单词"  << "解释" << "加入时间";
    tableWidget->setHorizontalHeaderLabels(headerList);
    tableWidget->setColumnWidth(0, 60);
    tableWidget->setColumnWidth(1, 82);
    tableWidget->setColumnWidth(2, 82);
    for(int i=0; i<row; i++)
    {
        tableWidget->setRowHeight(i, 23);
    }
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setShowGrid(false);
    QHeaderView *headerview = tableWidget->verticalHeader();
    headerview->setHidden(true);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QTableWidgetItem *item1, *item2, *item3;
    for(int i=0; i<row; i++)
    {
            item1 = new QTableWidgetItem("");
            item2 = new QTableWidgetItem("");
            item3 = new QTableWidgetItem("");
            item1->setTextAlignment(Qt::AlignCenter);
            item2->setTextAlignment(Qt::AlignCenter);
            item3->setTextAlignment(Qt::AlignCenter);

            tableWidget->setItem(i, 0, item1);
            tableWidget->setItem(i, 1, item2);
            tableWidget->setItem(i, 2, item3);

    }
    remindLabel = new QLabel(this);
    addButton = new QPushButton(this);
    deleteButton = new QPushButton(this);
    preButton = new QPushButton(this);
    backButton = new QPushButton(this);
    nextButton = new QPushButton(this);

    backButton->setGeometry(10, 6, 40, 19);
    remindLabel->setGeometry(173, 30, 24, 40);
    remindLabel->setText("0");
    remindLabel->setStyleSheet("font-size:20px");
    remindLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
    addButton->setGeometry(94, 419, 80, 35);
    deleteButton->setGeometry(175, 419, 80, 35);
    preButton->setGeometry(2, 210, 17, 33);
    nextButton->setGeometry(251, 210, 17, 33);
    addButton->setStyleSheet("background-color:transparent");
    deleteButton->setStyleSheet("background-color:transparent");
    preButton->setStyleSheet("background-color:transparent");
    nextButton->setStyleSheet("background-color:transparent");
    backButton->setStyleSheet("background-color:transparent");
    addDialog = new dialog(this);
    pageLabel = new QLabel(this);
    pageLabel->setGeometry(32, 410, 100, 40);
    QString string1 = QString::number(currentPage);
    QString string2 = QString::number(TotalPages);
    QString string = string1 + "/" + string2;
    pageLabel->setText(string);
    connect(addButton, SIGNAL(clicked()), addDialog, SLOT(show()));
    connect(addDialog->ensureButton, SIGNAL(clicked()), this, SLOT(add()));
    connect(addDialog->ensureButton, SIGNAL(clicked()), this, SLOT(clear()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteRow()));
    connect(backButton, SIGNAL(clicked()), this, SLOT(back()));
    connect(preButton, SIGNAL(clicked()), this, SLOT(prePage()));
    connect(nextButton, SIGNAL(clicked()), this, SLOT(nextPage()));

}
//public
void newWordManageWindow::update()
{

    TotalPages = newWordList.size()/row+1;       //更新页数  且要更新内容
    qDebug() << TotalPages << currentPage;
    if(newWordList.size()!=0)
    {
        if(currentPage == TotalPages)
        {
            for(int i=0; i<row; i++)
            {
                if(i<newWordList.size()%row)
                {
                    tableWidget->item(i, 0)->setText(newWordList[(currentPage-1)*row+i].spell);
                    tableWidget->item(i, 1)->setText(newWordList[(currentPage-1)*row+i].meaning);
                    tableWidget->item(i, 2)->setText(newWordList[(currentPage-1)*row+i].addTime);
                }
                else
                {
                    tableWidget->item(i, 0)->setText("");
                    tableWidget->item(i, 1)->setText("");
                    tableWidget->item(i, 2)->setText("");

                }
            }
        }
        else
        {
            for(int i=0; i<row; i++)
            {
                tableWidget->item(i, 0)->setText(newWordList[(currentPage-1)*row+i].spell);
                tableWidget->item(i, 1)->setText(newWordList[(currentPage-1)*row+i].meaning);
                tableWidget->item(i, 2)->setText(newWordList[(currentPage-1)*row+i].addTime);
            }
        }
    }
    else
    {

        tableWidget->clearContents();
    }
    setNum(newWordList.size());
    QString string1 = QString::number(currentPage);
    QString string2 = QString::number(TotalPages);
    QString string = string1 + "/" +string2;
    pageLabel->setText(string);
}



void newWordManageWindow::add()
{
    QString spell = addDialog->spellEdit->text();
    QString meaning = addDialog->meaningEdit->text();
    insertWord(spell, meaning);
}
void newWordManageWindow::clear()
{
    addDialog->spellEdit->clear();
    addDialog->meaningEdit->clear();
    addDialog->spellEdit->setFocus();
    addDialog->hide();
}

void newWordManageWindow::insertWord(QString spell, QString meaning)
{
    QDialog *dialog = new QDialog(addDialog);
    dialog->setWindowTitle("重复");
    dialog->resize(200, 110);
    QLabel *label = new QLabel(dialog);
    QLabel *labelText = new QLabel(dialog);
    label->setStyleSheet("background-color:lightblue");
    labelText->setAlignment(Qt::AlignCenter);
    labelText->setGeometry(30, 0, 140, 70);
    label->setGeometry(0, 0, this->width(), this->height());
    QPushButton *yesButton = new QPushButton(dialog);
    yesButton->setGeometry(140, 70, 55, 20);
    yesButton->setText("返回");
    yesButton->setStyleSheet("color:black");
    bool fail = false;
    if(spell.size()==0)
    {
        labelText->setText("单词不能为空！");
        fail = true;
    }
    else if(meaning.size()==0)
    {
        labelText->setText("释义不能为空！");
        fail = true;

    }
    for(int i=0; i<newWordList.size(); i++)
    {    
        if(newWordList[i].spell==spell)
        {
            labelText->setText("您已经添加过这个生词了！");

        }
        fail = true;
        break;

    }
    if(fail)
    {
        dialog->show();
        connect(yesButton,SIGNAL(clicked()), dialog, SLOT(close()));

    }
    if(!fail)
    {
        QDateTime sysTime = QDateTime::currentDateTime();
        QStringList list = sysTime.toString("yyyy-MM-dd").split('-');
        QString time = list[0]+list[1]+list[2];
        NEWWORD newword = { meaning, spell, time };
        newWordList.push_front(newword);
        qDebug() << currentPage << " " << TotalPages;
        update();
    }

}
void newWordManageWindow::deleteRow()
{
    if(newWordList.size()!=0)
    {
        int index = tableWidget->currentRow();
        for(int i=0; i<newWordList.size(); i++)
        {
            if(tableWidget->item(index, 0)->text()==newWordList[i].spell)
            {

                newWordList.remove(i);
                qDebug() << newWordList.size();
                update();
                break;
            }
        }
    }

}

void newWordManageWindow::setNum(int number)
{
    QString num;
    num = QString::number(number, 10);
    remindLabel->setText(num);
}

//private slots
void newWordManageWindow::prePage()
{
    if(currentPage == 1)
        return;
    else
    {
        currentPage--;
        update();
    }
}
void newWordManageWindow::nextPage()
{
    if(currentPage == TotalPages)
        return;
    else
    {
        currentPage++;
        update();
    }
}

void newWordManageWindow::back()
{
    userWindow *backwindow = new userWindow(user);
    backwindow->show();
    this->close();
}

newWordManageWindow::~newWordManageWindow()
{

}
