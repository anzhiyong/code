#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton(this);
    button->setText("点我一下试试");
    button->move(300, 200);

    connect(button, &QPushButton::clicked, this, &Widget::close);
}

Widget::~Widget()
{
    delete ui;
}

