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
#include <QDebug>

class dialog:public QDialog
{
    Q_OBJECT
public:
    dialog(QWidget *parent);
private:
//    QLabel *spellLabel;
//    QLabel *meaningLabel;
    QLineEdit *spellEdit;
    QLineEdit *meaningEdit;
    QPushButton *ensureButton;
    QPushButton *cancelButton;
};

#endif // DIALOG_H
