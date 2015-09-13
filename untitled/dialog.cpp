#include "dialog.h"

dialog::dialog(QWidget *parent)
{
    QVBoxLayout *layout = new QVBoxLayout();
//    spellLabel = new QLabel();
//    meaningLabel = new QLabel();
    spellEdit = new QLineEdit();
    spellEdit->setPlaceholderText("在此输入单词拼写");
    meaningEdit =  new QLineEdit();
    meaningEdit->setPlaceholderText("在此输入其释义");
    ensureButton = new QPushButton();
    ensureButton->setText("确定");
    cancelButton = new QPushButton();
    cancelButton->setText("取消");
    layout->addWidget(spellEdit);
    layout->addWidget(meaningEdit);
    QHBoxLayout *hlayout = new QHBoxLayout();
    QSpacerItem *item1 = new QSpacerItem(80, 20);
    hlayout->addSpacerItem(item1);
    hlayout->addWidget(ensureButton);
    hlayout->addWidget(cancelButton);
    layout->addLayout(hlayout);
    this->setLayout(layout);

    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
}


