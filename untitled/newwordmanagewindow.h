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
#include "dialog.h"

class newWordManageWindow:public QWidget
{
public:
    newWordManageWindow();
    ~newWordManageWindow();
private:
    QVBoxLayout *mainLayout;
    QTableWidget *tableWidget;
    QLabel *remindLabel;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *nextButton;
    QPushButton *preButton;
    dialog *addDialog;
};



#endif // NEWWORDMANAGEWINDOW_H
