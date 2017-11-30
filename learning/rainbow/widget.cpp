#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

void Widget::paintEvent(QPaintEvent *e) // protected
{
    QPainter painter(this);
    int width = this->width();
    int height = this->height();

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::red));
    painter.drawEllipse(QPoint(width / 2, height), width / 2, height);

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::green));
    painter.drawEllipse(QPoint(width / 2, height), width / 2 - 50, height - 50);

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::yellow));
    painter.drawEllipse(QPoint(width / 2, height), width / 2 - 100, height - 100);

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::green));
    painter.drawEllipse(QPoint(width / 2, height), width / 2 - 150, height - 150);

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::blue));
    painter.drawEllipse(QPoint(width / 2, height), width / 2 - 200, height - 200);

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::black));
    painter.drawEllipse(QPoint(width / 2, height), width / 2 - 250, height - 250);

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::red));
    painter.drawEllipse(QPoint(width / 2, height), width / 2 - 300, height - 300);
}

Widget::~Widget()
{
    delete ui;
}
