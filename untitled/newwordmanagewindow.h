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
#include "dialog.h"

#include "userwindow.h"

class newWordManageWindow:public QWidget
{
    Q_OBJECT
public:
    newWordManageWindow();
    ~newWordManageWindow();
    dialog *addDialog;

private:
    QLabel *background;
    QTableWidget *tableWidget;
    QLabel *remindLabel;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *nextButton;
    QPushButton *preButton;
    QPushButton *backButton;

    static int count;  //表格中有数据的单词个数
public:
    void deleteWord(int row);
    void setNum(int number);
private slots:
    void insertWord(QString spell, QString meaning);
    void deleteRow();
    void back();
    void add();
    void clear();
};



#endif // NEWWORDMANAGEWINDOW_H
