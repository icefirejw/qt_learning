#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFocusPolicy(Qt::StrongFocus);

    snake = new Snake();

    snake->getSnakeWorkspaceSize(&snake_width, &snake_height);

    my_timer = new QTimer(this);

    //connect(my_timer,SIGNAL(my_timer->timeout()),this,SLOT(showSnake));
    connect(my_timer,&QTimer::timeout,this,[=](){
        snakeMove();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()){
        case Qt::Key_Space:
            if (!my_timer->isActive())
                my_timer->start(100);
            break;
        case Qt::Key_Up:
        case Qt::Key_W:
            snake->setSnakeDirect(1);
            break;
        case Qt::Key_Down:
        case Qt::Key_S:
            snake->setSnakeDirect(2);
            break;
        case Qt::Key_Left:
        case Qt::Key_A:
            snake->setSnakeDirect(3);
            break;
        case Qt::Key_Right:
        case Qt::Key_D:
            snake->setSnakeDirect(4);
            break;
    }
    //qDebug("key press:%d", snake->getSnakeDirect());
}

//update默认会调用该函数
void MainWindow::paintEvent(QPaintEvent *event)
{
    int i,j;
    QPainter painter(this);
    QFont font;
    font.setPointSize(10);
    painter.setFont(font);

    for (i=0; i<snake_width+1; ++i)
        for (j=0; j<snake_height+1; ++j)
        {
            int s_v;
            QString s;
            s_v = snake->getSnakeWorkspaceValue(i,j);
            if (s_v > 1){ //蛇身 *
                s = "*";
            }
            else if (s_v == 1){ //蛇头 @
                s="@";
            }
            else if (s_v == -2) { //边界 #
                s="#";
            }
            else if (s_v == -1) { //食物 F
                s="F";
            }
            else { //空白处 空格‘ ’
                s=" ";
            }

            painter.drawText(SNAKE_SIZE+SNAKE_SIZE*i,SNAKE_SIZE+SNAKE_SIZE*j,s);
        }

    QString scoreS;
    scoreS = "Score: ";
    scoreS.append(QString::number(snake->getSnakeScore()));
    scoreS.append("                           CopyRights by Sam&Joe");
    painter.drawText(SNAKE_SIZE,SNAKE_SIZE+(SNAKE_SIZE)*(snake_height+3),scoreS);

    //qDebug("aaa!aaa");
    return;
}

void MainWindow::snakeMove()
{
    int ret;
    ret = snake->updateSnake();

    update();

    if (ret < 0)
    {
        QMessageBox::information(NULL, "Snake","Game Over!" );
        exit(0);
    }
}
