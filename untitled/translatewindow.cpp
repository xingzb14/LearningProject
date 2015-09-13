#include "translatewindow.h"

translateWindow::translateWindow()
{
    this->resize(270, 400);
    this->setWindowFlags(Qt::FramelessWindowHint);
    textEdit1.setParent(this);
    textEdit2.setParent(this);
    textEdit1.setGeometry(30, 50, 210, 130);
    textEdit1.setPlaceholderText("在此输入要翻译的文本");
    textEdit2.setGeometry(30, 220, 210, 130);
    textEdit2.setPlaceholderText("翻译结果");
    translationButton.setParent(this);
    translationButton.setGeometry(180, 190, 50, 20);
    translationButton.setText("翻译");

}

translateWindow::~translateWindow()
{

}

