#include "widget.h"
#include "ui_widget.h"
#include <Qvector>
#include <Qstring>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(smorozit()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::smorozit()
{
    QVector<QString> mydrosts {"ONE MORE THAN TWO", "MOON IS NOT EARTH", "HELL IS FOR FOR ME"};
    ui->label->setText(mydrosts[rand() % mydrosts.size()]);
}
