#ifndef MOREWINDOW_H
#define MOREWINDOW_H
#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QComboBox>
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
    moreWindow();
    ~moreWindow();
private:
    QLabel *toplabel;
    QPushButton *settingModel;       //设置模式
    QLabel *settingBook;        //设置单词书
    QComboBox *BookBox;         //单词书选项
    QPushButton *logoffButton;       //注销按钮
    QPushButton *aboutButton;        //关于
};

#endif // MOREWINDOW_H
