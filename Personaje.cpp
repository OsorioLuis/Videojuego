#include "Personaje.h"
#include "Proyectil.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QKeyEvent>
#include "Enemigo.h"

void Personaje::keyPressEvent(QKeyEvent *event)
{

    //informacion del evento queda guardada en el objeto evento
    if(event->key() == Qt::Key_Left){
        setPos(x()-10, y());
    }else if(event->key() == Qt::Key_Right){
        setPos(x()+10, y());
    }else if(event->key() == Qt::Key_Up){
        setPos(x(), y()-10);
    }else if(event->key() == Qt::Key_Down){
        setPos(x(), y()+10);
    }else if(event->key() == Qt::Key_Space){
        Proyectil *proyectil = new Proyectil();
        //tenemos que añadirlo a la escena
        scene()->addItem(proyectil);
        //posicion del proyectil
        proyectil->setPos(x(), y());
    }

    qDebug() << "Haz presionado una tecla";
}
//este metodo debe ir en la clase entidad
void Personaje::spawn(){
    //creacion de enemigo
    Enemigo * enemigo = new Enemigo();
    scene()->addItem(enemigo);
}
