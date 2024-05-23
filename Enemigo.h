#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <QGraphicsRectItem>
#include <QObject>

class Enemigo : public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemigo();
public slots:
    void moverEnemigo();
};
#endif // ENEMIGO_H
