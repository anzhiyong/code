#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    myButton->setText("Hello world!");
    connect(myButton, &QPushButton::clicked, this, &Widget::clickHandle);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::clickHandle()
{
    if(myButton->text() == QString("Hello world!"))
    {
        myButton->setText("你好!");
    }
    else
    {
        myButton->setText("Hello world!");
    }


}
