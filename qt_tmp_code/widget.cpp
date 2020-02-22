#include "widget.h"
#include "ui_widget.h"
#include <QMenuBar>
#include <QAction>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QMenuBar * menu = ui->menuBar();
    setMenuBar(menu);

    QAction * actOpen = new QAction("打开",this);
    menu->addAction(actOpen);
}

Widget::~Widget()
{
    delete ui;
}
