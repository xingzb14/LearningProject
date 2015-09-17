#include "newwordmanagewindow.h"

int row = 13;
int column = 3;
int newWordManageWindow::count = 0;
newWordManageWindow::newWordManageWindow()
{
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
    connect(addButton, SIGNAL(clicked()), addDialog, SLOT(show()));
    connect(addDialog->ensureButton, SIGNAL(clicked()), this, SLOT(add()));
    connect(addDialog->ensureButton, SIGNAL(clicked()), this, SLOT(clear()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteRow()));
    connect(backButton, SIGNAL(clicked()), this, SLOT(back()));

}
//public
void newWordManageWindow::deleteRow()
{
    int currentRow = tableWidget->currentRow();
    deleteWord(currentRow);
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
    bool repeated = false;
    for(int i=0; i<count; i++)
    {
        if(tableWidget->item(i, 0)->text()==spell)
        {
            QDialog *dialog = new QDialog(addDialog);
            dialog->setWindowTitle("重复");
            dialog->resize(200, 110);
            QLabel *label = new QLabel(dialog);
            QLabel *labelText = new QLabel(dialog);
            label->setStyleSheet("background-color:lightblue");
            labelText->setText("您已经添加过这个生词了");
            labelText->setAlignment(Qt::AlignCenter);
            labelText->setGeometry(30, 0, 140, 70);
            label->setGeometry(0, 0, this->width(), this->height());
            QPushButton *yesButton = new QPushButton(dialog);
            yesButton->setGeometry(140, 70, 55, 20);
            yesButton->setText("返回");
            yesButton->setStyleSheet("color:black");
            dialog->show();
            connect(yesButton,SIGNAL(clicked()), dialog, SLOT(close()));
            repeated = true;
            break;
        }
    }
    if(repeated == false)
    {
    QTableWidgetItem *item1 = new QTableWidgetItem(spell);
    QTableWidgetItem *item2 = new QTableWidgetItem(meaning);
    item1->setTextAlignment(Qt::AlignCenter);
    item2->setTextAlignment(Qt::AlignCenter);
    tableWidget->setItem(count, 0, item1);
    tableWidget->setItem(count, 1, item2);
    QDateTime sysTime = QDateTime::currentDateTime();
    QStringList list = sysTime.toString("yyyy-MM-dd").split('-');
    QString time = list[0]+list[1]+list[2];
    tableWidget->setItem(count, 2, new QTableWidgetItem(time));
    count++;
    setNum(count);
    }

}
void newWordManageWindow::deleteWord(int row)
{
    qDebug() << tableWidget->currentRow();
    if(tableWidget->isItemSelected(tableWidget->currentItem()))
    {
        if(count==0)
        qDebug() << "no ";
    else
        {
            QList<QTableWidgetItem *> deleteItem = tableWidget->selectedItems();
            deleteItem.clear();
            tableWidget->removeRow(row);
            count--;

        }
    }
    else
    {
        qDebug() << "select";
    }
    setNum(count);

}

void newWordManageWindow::setNum(int number)
{
    QString num;
    num = QString::number(number, 10);
    remindLabel->setText(num);
}

//private slots
void newWordManageWindow::back()
{
    userWindow *backwindow = new userWindow();
    backwindow->show();
    this->close();
}

newWordManageWindow::~newWordManageWindow()
{

}
