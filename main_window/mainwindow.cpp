#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(640,480);
    setWindowTitle("测试窗口");

    ////////////////////////////////////
    //菜单栏
    ////////////////////////////////////
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

    /////////////////////////////////////////////////
    //工具栏
    ////////////////////////////////////////////////
    //新建工具栏
    QToolBar * toolBar = new QToolBar(this);
    //将工具栏添加到窗口
    addToolBar(Qt::TopToolBarArea,toolBar);
    //设置工具栏可停靠的位置
    toolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::TopToolBarArea);
    //设置工具栏不能浮窗
    toolBar->setFloatable(false);

    //工具栏添加菜单项
    toolBar->addAction(newAction);

    //工具栏添加按钮
    QPushButton * btn = new QPushButton(this);
    btn->setText("test");
    toolBar->addWidget(btn);

    ///////////////////////////////////////////
    //状态栏
    ///////////////////////////////////////////
    //新建状态栏
    QStatusBar * stBar = statusBar();
    setStatusBar(stBar);
    //添加状态栏信息
    QLabel * leftLabel = new QLabel("左侧",this);
    QLabel * rightLabel = new QLabel("右侧",this);
    stBar->addWidget(leftLabel);
    stBar->addPermanentWidget(rightLabel);

    ////////////////////////////////////////
    //铆接部件(悬浮窗口）
    ////////////////////////////////////////
    QDockWidget * dock = new QDockWidget("铆接部件",this);
    addDockWidget(Qt::BottomDockWidgetArea, dock);
    dock->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::TopDockWidgetArea);

    ////////////////////////////////////////
    //核心部件
    ////////////////////////////////////////
    QTextEdit * textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
}

MainWindow::~MainWindow()
{

}
