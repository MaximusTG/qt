#ifndef BALL_H
#define BALL_H


const double GRAVITY = 5;
const int WIDTH = 1100;
const int HEIGHT = 700;


class Ball {
private:
    double x0_;
    double y0_;
    double x_;
    double y_;
    double radius_;
    double x_acseleration_;
    double y_acseleration_;
    double x_starting_speed_;
    double y_starting_speed_;
    double time_;
public:
    Ball();
    Ball(double x, double y, double radius, double x_acseleration, double y_acseleration, double x_starting_speed, double y_starting_speed, double time);
    void reconstruct(double x, double y, double radius, double x_acseleration, double y_acseleration, double x_starting_speed, double y_starting_speed, double time);
    double get_x();
    double get_y();
    double get_radius();
    void set_acseleration(double x_acseleration, double y_acseleration);
    void set_time(double time);
    void increase_time_by_tick();
    void recalculate_position();
    void recalculate_position_ignore_acseleration();
    void normalize_coords();
    void normalize_coords_and_bounce();
};

#endif // BALL_H
