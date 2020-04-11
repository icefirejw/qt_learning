#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // TreeWidget 树控件使用
    // 1.设置树标签（fromLocal8Bit防止乱码）
    ui->treeWidget->setHeaderLabels(QStringList()<<QString::fromLocal8Bit("英雄")<<QString::fromLocal8Bit("描述"));

    // 2.添加树项目
    // 2.1 添加根节点
    QTreeWidgetItem *itemL = new QTreeWidgetItem(QStringList()<<QString::fromLocal8Bit("力量"));
    QTreeWidgetItem *itemM = new QTreeWidgetItem(QStringList()<<QString::fromLocal8Bit("敏捷"));
    QTreeWidgetItem *itemZ = new QTreeWidgetItem(QStringList()<<QString::fromLocal8Bit("智力"));
    ui->treeWidget->addTopLevelItem(itemL);
    ui->treeWidget->addTopLevelItem(itemM);
    ui->treeWidget->addTopLevelItem(itemZ);

    // 2.2 添加子节点
    QStringList heroL1;
    heroL1 << QString::fromLocal8Bit("八戒") << QString::fromLocal8Bit("吃啊吃啊");

    QTreeWidgetItem * itemL1 = new QTreeWidgetItem(heroL1);
    itemL->addChild(itemL1);

    // TableWidget 表控件使用
    // 1. 设置列数
    ui->tableWidget->setColumnCount(3);

    // 2. 设置列名
    QStringList columnName;
    columnName << QString::fromLocal8Bit("姓名") << QString::fromLocal8Bit("性别") << QString::fromLocal8Bit("年纪");
    ui->tableWidget->setHorizontalHeaderLabels(columnName);

    // 3. 设置行数
    ui->tableWidget->setRowCount(5);

    // 4. 添加表项目
    QStringList nameList;
    QStringList sexList;

    nameList << QString::fromLocal8Bit("刘备") << QString::fromLocal8Bit("关羽") \
             << QString::fromLocal8Bit("张飞") << QString::fromLocal8Bit("孙尚香");
    sexList << QString::fromLocal8Bit("男") << QString::fromLocal8Bit("男") \
            << QString::fromLocal8Bit("男") << QString::fromLocal8Bit("女");

    for (int i = 0; i<4; i++) {
        int col = 0;
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(sexList.at(i)));
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(18+i)));

    }

}

Widget::~Widget()
{
    delete ui;
}

