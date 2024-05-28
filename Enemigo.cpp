#include "Enemigo.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QRandomGenerator>
#include <QGraphicsPixmapItem>

Enemigo::Enemigo(int nivel, Personaje *objetivo) : QGraphicsPixmapItem(), objetivo(objetivo){
    //en el constructor se paso la inicializacion del miembro objetivo
    //generacion de posicion aleatoria
    int aleatX = QRandomGenerator::global()->bounded(800 + 200);
    int aleatY = QRandomGenerator::global()->bounded(600 + 200);
    setPos(aleatX, aleatY);

    generico.load(":/texturas/enemigo.png");
    QPixmap scaled_generico = generico.scaled(70, 70);
    setPixmap(scaled_generico);

    //establecer dificultad de enemigo
    if(nivel == 1){
        nivelActual = 1;
    }else if(nivel == 2){
        nivelActual = 2;
    }
    //para el manejo de impactos

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

void Enemigo::recibirImpacto(){
    cuentaImpact++;
    if(cuentaImpact == nivelActual){
        emit eliminado(); //es una señal que va junto con la señal de cambio puntuacion
        scene()->removeItem(this);
        delete this;
    }

}
