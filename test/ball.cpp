#include "ball.h"
#include <QDebug>


Ball::Ball()
{
    x_ = 0;
    y_ = 0;
    radius_ = 0;
    x_acseleration_ = 0;
    y_acseleration_ = 0;
    x_starting_speed_ = 0;
    y_starting_speed_ = 0;
    time_ = 0;
}

Ball::Ball(int mode, double x, double y, double radius, double elasticity, double x_acseleration, double y_acseleration, double x_starting_speed, double y_starting_speed, double time)
{
    mode_ = mode;
    x0_ = x;
    y0_ = y;
    x_ = x;
    y_ = y;
    radius_ = radius;
    elasticity_ = elasticity;
    x_acseleration_ = x_acseleration;
    y_acseleration_ = y_acseleration;
    x_starting_speed_ = x_starting_speed;
    y_starting_speed_ = y_starting_speed;
    x_current_speed_ = x_starting_speed_;
    y_current_speed_ = y_starting_speed_;
    time_ = time;
}

void Ball::reconstruct(int mode, double x, double y, double radius, double elasticity, double x_acseleration, double y_acseleration, double x_starting_speed, double y_starting_speed, double time)
{
    mode_ = mode;
    x0_ = x;
    y0_ = y;
    x_ = x;
    y_ = y;
    radius_ = radius;
    elasticity_ = elasticity;
    x_acseleration_ = x_acseleration;
    y_acseleration_ = y_acseleration;
    x_starting_speed_ = x_starting_speed;
    y_starting_speed_ = y_starting_speed;
    x_current_speed_ = x_starting_speed_;
    y_current_speed_ = y_starting_speed_;
    time_ = time;
}

double Ball::get_x()
{
    return x_;
}

double Ball::get_y()
{
    return y_;
}

double Ball::get_radius()
{
    return radius_;
}

double Ball::get_time()
{
    return time_;
}

void Ball::set_acseleration(double x_acseleration, double y_acseleration)
{
    x_acseleration_ = x_acseleration;
    y_acseleration_ = y_acseleration;
}

void Ball::set_time(double time)
{
    time_ = time;
}

void Ball::increase_time_by_tick()
{
    time_ += 0.01;
}

void Ball::recalculate_position()
{
    double new_x = x0_ + x_starting_speed_ * time_ + x_acseleration_ * time_ * time_ / 2;
    double new_y = y0_ + y_starting_speed_ * time_ + y_acseleration_ * time_ * time_ / 2;

    x_ = new_x;
    y_ = new_y;

    normalize_coords_and_bounce();
}

void Ball::recalculate_position_ignore_acseleration()
{
    double new_x = x0_ + x_starting_speed_ * time_;
    double new_y = y0_ + y_starting_speed_ * time_;

    x_ = new_x;
    y_ = new_y;

    normalize_coords_and_bounce();
}

void Ball::recalculate_current_speed()
{
    x_current_speed_ = x_starting_speed_ + x_acseleration_ * time_;
    y_current_speed_ = y_starting_speed_ + y_acseleration_ * time_;

    if (abs(x_current_speed_) < THE_SMALLEST_NUMBER) {
        x_current_speed_ = 0;
    }
    if (abs(y_current_speed_) < THE_SMALLEST_NUMBER) {
        y_current_speed_ = 0;
    }
}

void Ball::normalize_coords()
{
    if (x_ -  radius_ < 0) {
        x_ = radius_;
    } else if (x_ + radius_ >= WIDTH){
        x_ = WIDTH - radius_;
    }
    if (y_ -  radius_ < 0) {
        y_ = radius_;
    } else if (y_ + radius_ >= HEIGHT){
        y_ = HEIGHT - radius_;
    }
}

void Ball::normalize_coords_and_bounce()
{
    recalculate_current_speed();
    if (x_ -  radius_ < 0 || x_ + radius_ > WIDTH) {
        if (x_ -  radius_ < 0) {
            x_ = radius_;
        } else {
            x_ = WIDTH - radius_;
        }
        qDebug() << "BUM_X";
        if (mode_ == MODE_SIDE_FALLER) {
            reconstruct(mode_, x_, y_, radius_, elasticity_, x_acseleration_, y_acseleration_, - x_current_speed_ * elasticity_, y_current_speed_, 0);
        } else if (mode_ == MODE_STRAIGHT_FLYER) {
            qDebug() << "SPD " << x_starting_speed_ << " " << x_current_speed_;
            reconstruct(mode_, x_, y_, radius_, elasticity_, - x_acseleration_, y_acseleration_, - x_current_speed_ * elasticity_, y_current_speed_, 0);
            qDebug() << "SPD " << x_starting_speed_ << " " << x_current_speed_;
        }
    }
    if (y_ -  radius_ < 0 || y_ + radius_ > HEIGHT) {
        if (y_ -  radius_ < 0) {
            y_ = radius_;
        } else {
            y_ = HEIGHT - radius_;
        }
        qDebug() << "BUM_Y";
        if (mode_ == MODE_SIDE_FALLER) {
            reconstruct(mode_, x_, y_, radius_, elasticity_, x_acseleration_, y_acseleration_, x_current_speed_, - y_current_speed_ * elasticity_, 0);
        } else if (mode_ == MODE_STRAIGHT_FLYER) {
            reconstruct(mode_, x_, y_, radius_, elasticity_, x_acseleration_, - y_acseleration_, x_current_speed_, - y_current_speed_ * elasticity_, 0);
        }
    }
}
