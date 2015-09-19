#ifndef MOREWINDOW_H
#define MOREWINDOW_H
#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QComboBox>
#include "learningwindow.h"
#include "translatewindow.h"
#include "phrasewindow.h"
#include "morewindow.h"
//准备和userwindow合并成为一个
/* 界面：更多（包含设置）
 * 包括功能：
 *
 * 设置夜间模式
 * 设置单词书
 * 注销/用户切换
 * 关于
 */
class moreWindow:public QWidget
{
    Q_OBJECT
public:
    moreWindow(User *user);
    ~moreWindow();
private:
    User *user;
    QLabel *background;
    QPushButton *settingBook;        //设置单词书
    QComboBox *BookBox;         //单词书下拉框
    QPushButton *settingNumber;     //设置单词数
    QComboBox *NumberBox;           //单词数下拉框

    QPushButton *logoffButton;       //注销按钮
    QPushButton *aboutButton;        //关于

    //导航栏
    QPushButton translateButton;
    QPushButton phrase;
    QPushButton wordlearning;
    QPushButton aboutUser;
    QPushButton more;
private slots:
    void openTranslate();
    void openWordLearning();
    void openPhraseLearning();
    void openUser();
//    void openSetting();
};

#endif // MOREWINDOW_H
