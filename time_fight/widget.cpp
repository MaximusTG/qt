#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()), this, SLOT(decriment()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(increment()));
    timer.start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::decriment()
{
    --n;
    ui->lcdNumber->display(n);

    if (n <= 0) {
        close();
    }
}

void Widget::increment()
{
    ++n;
    ui->lcdNumber->display(n);
}
