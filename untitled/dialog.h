#ifndef DIALOG_H
#define DIALOG_H
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QLayout>
#include <Qlabel>
#include <QPushButton>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include "dialog.h"
class dialog:public QDialog
{
    Q_OBJECT
public:
    dialog(QWidget *parent);
public://    QLabel *spellLabel;
//    QLabel *meaningLabel;
//    newWordManageWindow *window;
    dialog* addDialog;      //*号放到后边 竟然就报错了？ 调了好长时间
    QLineEdit *spellEdit;
    QLineEdit *meaningEdit;
    QPushButton *ensureButton;
    QPushButton *cancelButton;
public slots:
//    void enter();

};

#endif // DIALOG_H
