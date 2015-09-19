#ifndef NEWWORDMANAGEWINDOW_H
#define NEWWORDMANAGEWINDOW_H
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QLayout>
#include <Qlabel>
#include <QPushButton>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QDebug>
#include <QDateTime>
#include <QMessageBox>
#include <QVector>
#include <QDateTime>
#include "dialog.h"

#include "userwindow.h"
typedef struct newWord
{
    QString meaning;
    QString spell;
    QString addTime;
}NEWWORD;

class newWordManageWindow:public QWidget
{
    Q_OBJECT
public:
    newWordManageWindow(User *user);
    ~newWordManageWindow();
    dialog *addDialog;

private:
    User *user;
    QLabel *background;
    QTableWidget *tableWidget;
    QLabel *remindLabel;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *nextButton;
    QPushButton *preButton;
    QPushButton *backButton;
    QLabel *pageLabel;
    QVector<NEWWORD> newWordList;       //存储生词的向量
    int row;       //表格行数
    int column;     //表格列数
    int currentPage;    //当前页数
    int TotalPages;     //总共页数
//    static int count;   //表格中有数据的单词个数
public:
    void setNum(int number);
    void update();
private slots:
    void insertWord(QString spell, QString meaning);
    void nextPage();        //下一页
    void prePage();         //上一页
    void deleteRow();
    void back();
    void add();
    void clear();
};



#endif // NEWWORDMANAGEWINDOW_H
