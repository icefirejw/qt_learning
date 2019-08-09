#include "mainwindow.h"
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(640,480);
    setWindowTitle("测试窗口");

    //新建菜单栏
    QMenuBar * bar = menuBar();
    //将菜单添加到窗口
    setMenuBar(bar);

    //添加文件菜单
    QMenu * fileMenu = bar->addMenu("文件");

    //添加菜单项
    QAction * newAction = fileMenu->addAction("新建");
    fileMenu->addSeparator();
    QAction * openAction = fileMenu->addAction("打开");



}

MainWindow::~MainWindow()
{

}
