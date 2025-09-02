#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(this, &Widget::mySignal, &Widget::handleMySignal);

    // emit mySignal();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleMySignal()
{
    this->setWindowTitle("处理自定义信号");
}

void Widget::on_pushButton_clicked()
{
    emit mySignal();
}

