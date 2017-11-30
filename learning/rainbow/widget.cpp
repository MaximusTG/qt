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
    painter.drawEllipse(QPoint(width / 2, height), width / 2 * 6 / 7, height * 6 / 7);

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::yellow));
    painter.drawEllipse(QPoint(width / 2, height), width / 2 * 5 / 7, height * 5 / 7);

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::green));
    painter.drawEllipse(QPoint(width / 2, height), width / 2 * 4 / 7, height  * 4 / 7);

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::blue));
    painter.drawEllipse(QPoint(width / 2, height), width / 2 * 3 / 7, height  * 3 / 7);

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::black));
    painter.drawEllipse(QPoint(width / 2, height), width / 2 * 2 / 7, height * 2 / 7);

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::red));
    painter.drawEllipse(QPoint(width / 2, height), width / 2 / 7, height / 7);
}

Widget::~Widget()
{
    delete ui;
}
