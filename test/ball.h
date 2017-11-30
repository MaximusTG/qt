#ifndef BALL_H
#define BALL_H


const double GRAVITY = 500;
const int WIDTH = 1100;
const int HEIGHT = 700;
const double TICK = 0.005;

const double THE_SMALLEST_NUMBER = 10.0;

const int MODE_STRAIGHT_FLYER = 1;
const int MODE_SIDE_FALLER = 2;


class Ball {
private:
    int mode_;
    double x0_;
    double y0_;
    double x_;
    double y_;
    double radius_;
    double elasticity_;
    double x_acseleration_;
    double y_acseleration_;
    double x_starting_speed_;
    double y_starting_speed_;
    double x_current_speed_;
    double y_current_speed_;
    double time_;
public:
    Ball();
    Ball(int mode, double x, double y, double radius, double elasticity, double x_acseleration, double y_acseleration, double x_starting_speed, double y_starting_speed, double time);
    void reconstruct(int mode, double x, double y, double radius, double elasticity, double x_acseleration, double y_acseleration, double x_starting_speed, double y_starting_speed, double time);
    double get_x();
    double get_y();
    double get_radius();
    double get_time();
    double get_x_speed();
    double get_y_speed();
    void set_acseleration(double x_acseleration, double y_acseleration);
    void set_time(double time);
    void increase_time_by_tick();
    void recalculate_position();
    void recalculate_position_ignore_acseleration();
    void recalculate_current_speed();
    void normalize_coords();
    void normalize_coords_and_bounce();
};

#endif // BALL_H
