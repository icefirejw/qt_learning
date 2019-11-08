#include "mywidget.h"
#include <QPushButton>

/*
 * 自定义信号和槽函数
 * 需求：
 * 自定义老师和学生类：Teacher类、Student类
 * ClassIsOver下课，老师发送自定义信号，饿了
 * 学生：响应信号，并且处理：请老师吃饭
 *
*/

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn = new QPushButton;

    this->resize(640,480);

    btn->setParent(this);
    btn->setText("my button");
    btn->setGeometry(100,100,100,50);

    connect(btn, &QPushButton::clicked, this, &QWidget::close);

    // 自定义类
    zt = new Teacher(this);
    st = new Student(this);

    connect(zt, &Teacher::hungry, st, &Student::treat);
    classIsOver();

}

void MyWidget::classIsOver()
{
    //使用**emit**出发信号
    emit zt->hungry();
}
MyWidget::~MyWidget()
{

}
