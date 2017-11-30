#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(redraw()));
    timer.start(10);
    ui->setupUi(this);


    srand(time(0));

    this->colors = QVector<int>{1, 1, 1};
    this->color_shifts = QVector<int>{1, 1, 1};
    this->priority_color_to_shift = COLOR_GREEN;
    this->ticks_to_change_priority = rand() % 20 + 10;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor::fromRgb(this->colors[COLOR_RED], this->colors[COLOR_GREEN], this->colors[COLOR_BLUE]));

    int width = this->width();
    int height = this->height();

    painter.drawRect(0,0, width, height);
}

void Widget::redraw()
{
    this->changeColor();
    this->repaint();
}

void Widget::changeColor()
{
    int random_color = rand() % 6;
    if (random_color == COLOR_RED) {
        this->colors[COLOR_RED] += this->color_shifts[COLOR_RED];
    } else if (random_color == COLOR_GREEN) {
        this->colors[COLOR_GREEN] += this->color_shifts[COLOR_GREEN];

    } else if (random_color == COLOR_BLUE) {
        this->colors[COLOR_BLUE] += this->color_shifts[COLOR_BLUE];
    } else {
        this->colors[this->priority_color_to_shift] += this->color_shifts[this->priority_color_to_shift];
        this->ticks_to_change_priority -= 1;
        if (this->ticks_to_change_priority <= 0) {
            this->ticks_to_change_priority = rand() % 20 + 10;
            this->priority_color_to_shift = rand() % 3;
        }
    }

    qDebug() << this->colors[COLOR_RED];
    qDebug() << this->colors[COLOR_GREEN];
    qDebug() << this->colors[COLOR_BLUE];

    for (int color = COLOR_RED; color <= COLOR_BLUE; ++color) {
        if (this->colors[color] < 0 || this->colors[color] > 255) {
            if (this->colors[color] < 0) {
                this->colors[color] = 1;
                this->color_shifts[color] *= -1;
            }
            if (this->colors[color] >= 255) {
                this->colors[color] = 254;
                this->color_shifts[color] *= -1;
            }
        } else {
            if (rand() % 100 == 0) {
                this->color_shifts[color] *= -1;
            }
        }
    }
}


