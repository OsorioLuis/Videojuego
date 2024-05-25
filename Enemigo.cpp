#include "Enemigo.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QRandomGenerator>

Enemigo::Enemigo(Personaje *objetivo) : QGraphicsRectItem(), objetivo(objetivo){
    //en el constructor se paso la inicializacion del miembro objetivo
    //generacion de posicion aleatoria
    int aleatX = QRandomGenerator::global()->bounded(800 + 200);
    int aleatY = QRandomGenerator::global()->bounded(600 + 200);
    setPos(aleatX, aleatY);

    setRect(0, 0, 40, 40);//dimensiones de hitbox

    //uso de slots para el movimiento del enemigo
    tiempo = new QTimer(this);
    connect(tiempo, &QTimer::timeout, this, &Enemigo::moverEnemigo);
    tiempo->start(25); //modificar este tiempo cambia la velocidad

}
void Enemigo::moverEnemigo(){
    //if(!objetivo) return;
    //si objetivo es un puntero nulo evita la ejecucion de las lineas
    //de abajo, esto se verificó con chatgpt al presentar errores con personaje

    //posicion del personaje
    qreal objetivoX = objetivo->x();
    qreal objetivoY = objetivo->y();

    //calculamos la direccion hacia el objetivo
    qreal direccionX = objetivoX - x();
    qreal direccionY = objetivoY - y();
    qreal distancia = std::sqrt(objetivoX * objetivoX + objetivoY * objetivoY); //pitagoras

    //normalizamos el vetor de direcion para luego determinar como se debe mover el enemigo
    if(distancia != 0){
        qreal velocidad = 4.0;
        qreal movimientoX = (direccionX / distancia) * velocidad;
        qreal movimientoY = (direccionY / distancia) * velocidad;
        setPos(x() + movimientoX, y() + movimientoY);
    }
}
