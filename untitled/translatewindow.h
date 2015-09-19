#ifndef TRANSLATEWINDOW_H
#define TRANSLATEWINDOW_H
#include "mainwindow.h"
#include <QWidget>
#include <QTextEdit>
#include "Trans.h"
class translateWindow:public QMainWindow
{
    Q_OBJECT
public:
    translateWindow(User *user);
    ~translateWindow();
private:
    User *user;
    Qt_Translation::BaiduTranslation m_translation;
    QLabel background;
    QTextEdit textEdit1;
    QTextEdit textEdit2;
    QPushButton translationButton;
    QPushButton translateButton;
    QPushButton phrase;
    QPushButton wordlearning;
    QPushButton aboutUser;
    QPushButton more;
private slots:
//    void openTranslate();
    void openWordLearning();
    void openPhraseLearning();
    void openUser();
    void openSetting();
    void translate();
};

#endif // TRANSLATEWINDOW_H
