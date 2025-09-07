#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(this, &Widget::mySignal1, this, &Widget::mySlots1);
    connect(this, &Widget::mySignal1, this, &Widget::mySlots2);
    connect(this, &Widget::mySignal2, this, &Widget::mySlots1);
    connect(this, &Widget::mySignal2, this, &Widget::mySlots3);

    //触发信号
    emit mySignal1();
    emit mySignal2();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mySlots1()
{
    qDebug() << "mySlots1";
}

void Widget::mySlots2()
{
    qDebug() << "mySlots2";
}

void Widget::mySlots3()
{
    qDebug() << "mySlots3";
}
