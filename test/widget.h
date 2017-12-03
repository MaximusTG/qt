#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QString>
#include <QVector>
#include <QPainter>
#include "ball.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    int sleeped = 3;
    Ui::Widget *ui;
    QTimer timer;
    QVector<Ball> balls;

private slots:
    void recalculate_objects_positions();

protected:
    void paintEvent(QPaintEvent * event);
};

#endif // WIDGET_H
