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
    timer.start(TICK * 1000);
    connect(&timer, SIGNAL(timeout()), this, SLOT(recalculate_objects_positions()));
    //balls = QVector<Ball>{Ball(MODE_SIDE_FALLER, 300, 300, 50, 0.8, 0, GRAVITY, 100, -100, 0), Ball(MODE_STRAIGHT_FLYER, 200, 200, 50, 1, 0, 0, -300, 300, 0)};
    //balls = QVector<Ball>{Ball(MODE_STRAIGHT_FLYER, 300, 300, 50, 1, 0, 0, 300, 0, 0), Ball(MODE_STRAIGHT_FLYER, 200, 300, 50, 1, 0, 0, -300, 0, 0)};
    for (int i = 0; i < 10; ++i) {
        balls.push_back(Ball(rand() % 2, rand() % WIDTH, rand() % HEIGHT, rand() % 25 + 50, 1, 0, 0, rand() % 200 + 100, rand() % 200 + 100, 0));
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::recalculate_objects_positions()
{
    for (int i = 0; i < balls.size(); ++i) {
        Ball ball = balls[i];
        ball.set_time(ball.get_time() + TICK);
        ball.recalculate_current_speed();
        ball.recalculate_position();
        balls[i] = ball;
    }
    for (int first_index = 0; first_index < balls.size(); ++first_index) {
        for (int second_index = first_index + 1; second_index < balls.size(); ++second_index) {
            balls[first_index].solve_collision(&balls[second_index]);
        }
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
        double radius = ball.get_radius();
        painter.drawEllipse(x - radius, y - radius, radius, radius);
    }
    if (sleeped) {
        sleeped -= 1;
        Sleep(500);
    }
}
