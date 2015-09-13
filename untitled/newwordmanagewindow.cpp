#include "newwordmanagewindow.h"
int row = 8;
int column = 3;
newWordManageWindow::newWordManageWindow()
{
    this->setMaximumSize(270, 400);
    this->setMinimumSize(270, 400);
    this->setWindowFlags(Qt::FramelessWindowHint);
    mainLayout = new QVBoxLayout(this);
    tableWidget = new QTableWidget(row, column);
    remindLabel = new QLabel();
    addButton = new QPushButton();
    deleteButton = new QPushButton();
    nextButton = new QPushButton();
    preButton = new QPushButton();

    remindLabel->setText("您的生词本中共有___个生词");
    remindLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(remindLabel);

    QStringList headerList;
    headerList << "单词"  << "解释" << "加入时间" ;
    tableWidget->setHorizontalHeaderLabels(headerList);
    tableWidget->setColumnWidth(0, 60);
    tableWidget->setColumnWidth(1, 88);
    tableWidget->setColumnWidth(2, 80);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
//    tableWidget->setShowGrid(false);
    QHeaderView *headerview = tableWidget->verticalHeader();
    headerview->setHidden(true);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    mainLayout->addWidget(tableWidget);

    QHBoxLayout *hlayout = new QHBoxLayout();
    hlayout->addWidget(preButton);
    preButton->setText("上页");
    hlayout->addWidget(nextButton);
    nextButton->setText("下页");
    hlayout->addWidget(addButton);
    addButton->setText("添加");
    hlayout->addWidget(deleteButton);
    deleteButton->setText("删除");
//    hlayout->setSpacing(10);
//    hlayout->addSpacing(40);
    mainLayout->addLayout(hlayout);
    qDebug() << "no";
    addDialog = new dialog(this);
    qDebug()<<"yes";
    connect(addButton, SIGNAL(clicked()), addDialog, SLOT(show()));

}

newWordManageWindow::~newWordManageWindow()
{

}
