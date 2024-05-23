#include "Enemigo.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

Enemigo::Enemigo() : QObject(), QGraphicsRectItem(){
    //generacion de posicion aleatoria
    int random = rand() % 700;
    setPos(random, 0);

    setRect(0, 0, 100, 100);
    QTimer *tiempo = new QTimer(this);
    connect(tiempo, SIGNAL(timeout()), this, SLOT(moverEnemigo()));
    tiempo->start(30);
}
void Enemigo::moverEnemigo(){
    setPos(x(), y()+5);
}
