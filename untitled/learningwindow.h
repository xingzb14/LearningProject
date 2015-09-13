#ifndef LEARNINGWINDOW_H
#define LEARNINGWINDOW_H
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QTextEdit>

class learningWindow:public QWidget
{
    Q_OBJECT
public:
    learningWindow();
    ~learningWindow();
private:
    QLabel *toplabel;
    QPushButton *backbutton;
    QLabel *wordLabel;           //单词拼写
    QLabel *wordmeaning;         //单词释义
    QLabel *sentenceLabel;       //例句翻译
    QTextEdit *noteEdit;
    QPushButton *ensure;
    QPushButton *nextButton;
    QPushButton *preButton;
};

#endif // LEARNINGWINDOW_H
