#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>

#include "snake.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    Ui::MainWindow *ui;

    int snake_width;
    int snake_height;
    Snake *snake;
    QTimer *my_timer;
    QPainter *painter;

    void keyPressEvent(QKeyEvent *e);

    void paintEvent(QPaintEvent *event);
    void snakeMove();
};
#endif // MAINWINDOW_H
