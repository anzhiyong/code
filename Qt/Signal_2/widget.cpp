#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton(this);
    button->setText("按钮");
    button->move(200, 200);
    connect(button, &QPushButton::clicked, this, &Widget::handleClick);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClick()
{
    //点击按钮后修改窗口标题
    Widget::setWindowTitle("点击按钮后修改的标题!");

}

