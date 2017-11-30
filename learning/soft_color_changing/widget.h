#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <Qtimer>
#include <QVector>

const int COLOR_RED = 0;
const int COLOR_GREEN = 1;
const int COLOR_BLUE = 2;

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
    QVector<int> colors;
    QVector<int> color_shifts;
    int priority_color_to_shift;
    int ticks_to_change_priority;
    QTimer timer;
    Ui::Widget *ui;

    void changeColor();

protected:
    void paintEvent(QPaintEvent* event);

protected slots:
    void redraw();
};

#endif // WIDGET_H
