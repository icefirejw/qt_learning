#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

    //自定义信号写到signals关键字处
signals:
    //自定义信号写法：
    //1.返回void
    //2.只需声明，无需实现
    //3.自定义的信号可以发生重载
    void hungry();

public slots:
};

#endif // TEACHER_H
