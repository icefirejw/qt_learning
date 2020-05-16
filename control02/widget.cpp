#include "widget.h"
#include "ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //通过按钮切换栈容器的内容(stacked widget)
    // 切换至 scroll widget
    connect(ui->btn_scroll,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    // 切换至 tool widget
    connect(ui->btn_tool,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    // 切换至 tab widget
    connect(ui->btn_tab,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    //通过按钮选择下拉菜单
    ui->combo_box->addItem(QString::fromLocal8Bit("平民"));
    ui->combo_box->addItem(QString::fromLocal8Bit("英雄"));
    ui->combo_box->addItem(QString::fromLocal8Bit("坏蛋"));
    connect(ui->btn_hero, &QPushButton::clicked, [=](){
        ui->combo_box->setCurrentIndex(1);
    });

    //利用label显示图片
    ui->label_img->setPixmap(QPixmap(":/img/test.png"));
    //利用label显示动图
    QMovie *qMovie = new QMovie(":/img/test.gif");
    ui->label_gif->setMovie(qMovie);
    //动图需要使用start方法来播放
    qMovie->start();

}

Widget::~Widget()
{
    delete ui;
}

