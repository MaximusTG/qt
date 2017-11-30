#include "widget.h"
#include "ui_widget.h"
#include <ctime>
#include <windows.h>
#include <QPainter>
#include <QDebug>
#include "ball.h"


int randint(int min, int max) {
    return rand() % max + min;
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    setGeometry(100, 100, WIDTH, HEIGHT);
    srand(time(0));
    ui->setupUi(this);
    timer.start(5);
    connect(&timer, SIGNAL(timeout()), this, SLOT(redraw()));
    balls = QVector<Ball>{Ball(300, 300, 50, 0, GRAVITY, 1, -1, 0), Ball(200, 200, 50, 0, GRAVITY, -1, 1, 0)};
}

Widget::~Widget()
{
    delete ui;
}

void Widget::redraw()
{
    for (int i = 0; i < balls.size(); ++i) {
        Ball ball = balls[i];
        ball.increase_time_by_tick();
        ball.recalculate_position_ignore_acseleration();
        balls[i] = ball;
    }
    this->repaint();
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QBrush(QColor::fromRgb(120,40,50)));
    for (int i = 0; i < balls.size(); ++i) {
        Ball ball = balls[i];
        double x = ball.get_x();
        double y = ball.get_y();
        // qDebug() << x << ' ' << y << '\n';
        double radius = ball.get_radius();
        painter.drawEllipse(x - radius, y - radius, radius, radius);
    }
    if (sleeped) {
        sleeped -= 1;
        Sleep(500);
    }
}
