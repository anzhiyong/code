#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::handleClick);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClick()
{
    this-> setWindowTitle("修改窗口标题");
    qDebug() << "handleClick";
}

void Widget::handleClick2()
{
    this->setWindowTitle("修改窗口标题2");
    qDebug() << "handleClick2";
}

void Widget::on_pushButton_2_clicked()
{
    //断开槽函数连接
    disconnect(ui->pushButton, &QPushButton::clicked, this, &Widget::handleClick);

    //连接handleClick2
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::handleClick2);

}

