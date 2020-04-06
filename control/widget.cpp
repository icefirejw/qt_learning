#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->resize(640,400);
    //radio button: set the default value
    ui->btn_man->setChecked(true);
    ui->radioButton_3->setChecked(true);

    //check box:get the check box's value
    connect(ui->checkBox, &QCheckBox::stateChanged, [=](int state){
        qDebug()<< "state=" << state;
    });

//    //list widget
//    //使用 QString::fromLocal8Bit 来将本地字符编码转换为 Unicode 形式的 QString
//    QListWidgetItem * item = new QListWidgetItem(QString::fromLocal8Bit("春眠不觉晓"));
//    // add the list item to list widget
//    ui->listWidget->addItem(item);
//    // set list alignment
//    item->setTextAlignment(Qt::AlignHCenter);

    QStringList list;
    list << QString::fromLocal8Bit("春眠不觉晓") << QString::fromLocal8Bit("处处闻啼鸟") \
         << QString::fromLocal8Bit("夜来风雨声") << QString::fromLocal8Bit("花落知多少");
    ui->listWidget->addItems(list);

}

Widget::~Widget()
{
    delete ui;
}

