/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label_red;
    QLabel *label_blue;
    QLabel *label_green;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        label_red = new QLabel(Widget);
        label_red->setObjectName(QStringLiteral("label_red"));
        label_red->setGeometry(QRect(20, 80, 121, 61));
        QFont font;
        font.setPointSize(20);
        label_red->setFont(font);
        label_blue = new QLabel(Widget);
        label_blue->setObjectName(QStringLiteral("label_blue"));
        label_blue->setGeometry(QRect(270, 80, 121, 61));
        label_blue->setFont(font);
        label_green = new QLabel(Widget);
        label_green->setObjectName(QStringLiteral("label_green"));
        label_green->setGeometry(QRect(150, 80, 121, 61));
        label_green->setFont(font);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label_red->setText(QString());
        label_blue->setText(QString());
        label_green->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
