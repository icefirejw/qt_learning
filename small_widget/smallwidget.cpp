#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    //spinbox 值修改的时候 进度条也跟着修改
    //原信号存在重载，需要定义函数指针明确使用哪一个信号函数
    void (QSpinBox:: * smallSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox,smallSignal, ui->hSlider, &QSlider::setValue);

    //进度条修改的时候 spinbox的值跟着修改
    connect(ui->hSlider,&QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

void SmallWidget::setValue(int v)
{
    ui->spinBox->setValue(v);
}

int SmallWidget::getValue()
{
    return ui->spinBox->value();
}

SmallWidget::~SmallWidget()
{
    delete ui;
}
