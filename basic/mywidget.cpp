#include "mywidget.h"
#include <QPushButton>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn = new QPushButton;

    this->resize(640,480);

    btn->setParent(this);
    btn->setText("my button");
    btn->setGeometry(100,100,100,50);

    connect(btn, &QPushButton::clicked, this, &QWidget::close);

}

MyWidget::~MyWidget()
{

}
