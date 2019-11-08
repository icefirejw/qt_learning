#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

    //自定义槽函数，写到public slots处，或者是全局函数，或写到public下，或是lambda表达式
public slots:
    //槽函数写法：
    //1.返回void
    //2.需要声明，需要实现
    //3.可以重载
    void treat();
    void treat(QString foodName);
};

#endif // STUDENT_H
