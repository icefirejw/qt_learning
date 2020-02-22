#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QAction>
#include <QDebug>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenuBar * bar = menuBar();
    setMenuBar(bar);

    QAction * actNew = new QAction("打开",this);
    bar->addAction(actNew);

    connect(actNew, &QAction::triggered, [=](){

//        QString filename = QFileDialog::getOpenFileName(this);
//        qDebug()<<"点击"<<filename;

//        QColor color = QColorDialog::getColor(QColor(255,0,0));
//        qDebug() << color.red() << " " << color.green() << " " << color.blue();


        bool ok;//是否有找到对应字体
        //QFont参数
        //     family:字体， pointSize:字号
        QFont font = QFontDialog::getFont(&ok, QFont("宋体", 33));
        qDebug() << font.family() << " " << font.pointSize()<< " " << font.italic() << " " << font.bold();
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
