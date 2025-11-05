#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    srand(time(0));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_yes_clicked()
{
    ui->label->setText("成功加入黑牛突击队!");
}


void Widget::on_pushButton_no_pressed()
{
    QRect rect = this->geometry();

    int width = rect.width();
    int height = rect.height();


    int x = random() % width;
    int y = random() % height;

    ui->pushButton_no->move(x, y);
}

