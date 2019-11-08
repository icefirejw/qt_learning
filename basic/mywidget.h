#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

#include <teacher.h>
#include <student.h>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();

    Teacher * zt;
    Student * st;

    void classIsOver();
};

#endif // MYWIDGET_H
