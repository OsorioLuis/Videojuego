#include "Proyectil.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "Enemigo.h"


Proyectil::Proyectil(QPointF &direccion): direccion(direccion), velocidad(5){

    //posicion inicial y tamaño
    proy.load(":/texturas/proy.png");
    setPixmap(proy);
    //conectar a slot
    QTimer *tiempo = new QTimer();
    connect(tiempo, SIGNAL(timeout()), this, SLOT(colisiones()));
    tiempo->start(10);
    //cada 50ms tiempo el proyectil será disparado
}

QPixmap Proyectil::getProyectil(){
    return proy;
}

void Proyectil::colisiones(){
    QList<QGraphicsItem*> itemsColisionados = collidingItems();
    for(QGraphicsItem *item : itemsColisionados){
        if(typeid(*item) == typeid(Enemigo)){
            //usamos dynamic_cast para hacer la conversion qgi a un puntero tipo enemigo
            //esto funciona ya que solo se hace en este condicional donde item apunta a un enemigo
            Enemigo *enemigo = dynamic_cast<Enemigo*>(item);
            if(enemigo){
                //la puntuacion se maneja en este metodo
                enemigo->recibirImpacto();
                //scene()->removeItem(this);
                delete this;
                return; //necesario para las lineas siguientes
            }
        }
    }
    //movimiento del proyectil
    setPos(x() + direccion.x() * velocidad, y() + direccion.y() * velocidad);
    //se elimina cuando este en la posicion 0 respectiva a la escena
    if(pos().y() + pixmap().height() < 0){
        scene()->removeItem(this);
        delete this; //hace referencia al mismo objeto que se le pasa a la señal en el constructor
    }
}

