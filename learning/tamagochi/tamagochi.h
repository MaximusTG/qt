#ifndef TAMAGOCHI_H
#define TAMAGOCHI_H

#include <QObject>

class Tamagochi : public QObject
{
    Q_OBJECT
public:
    explicit Tamagochi(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TAMAGOCHI_H