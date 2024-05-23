#include "Proyectil.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "Enemigo.h"

Proyectil::Proyectil(){

    //posicion inicial y tamaño
    setRect(0, 0, 5, 25);
    //conectar a slot
    QTimer *tiempo = new QTimer();
    connect(tiempo, SIGNAL(timeout()), this, SLOT(moverseUP()));
    tiempo->start(10);
    //cada 50ms tiempo el proyectil será disparado
}

void Proyectil::moverseUP()
{
    //si la bala choca con el enemigo
    QList<QGraphicsItem *> colliding_Items = collidingItems();
    for(int i = 0, n = colliding_Items.size(); i < n; i++){
        if(typeid(*(colliding_Items[i])) == typeid(Enemigo)){
            scene()->removeItem(colliding_Items[i]);
            scene()->removeItem(this);
            //eliminando de memoria
            delete colliding_Items[i];
            delete this;
            return;
        }
    }

    //movimiento del proyectil
    setPos(x(), y()-10);
    //se elimina cuando este en la posicion 0 respectiva a la escena
    if(pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this; //hace referencia al mismo objeto que se le pasa a la señal en el constructor
        qDebug() << "item eliminado";
    }
}
