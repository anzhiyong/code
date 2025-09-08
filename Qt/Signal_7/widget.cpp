#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton(this);
    button->setText("按钮");
    button->move(200, 200);
    connect(button, &QPushButton::clicked, this, [button, this](){
        qDebug() << "lambda被执行";
        button->move(500, 500);
        this->move(0, 0);
    });

}

Widget::~Widget()
{
    delete ui;
}
