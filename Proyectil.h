#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <QVector2D>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include "Juego.h"

//para acceder a puntuacion
extern Juego *juego; //objeto global juego

class Proyectil: public QObject, public QGraphicsPixmapItem{
    //macro
    Q_OBJECT
public:
    Proyectil(QPointF &direccion); //constructor, se establece la direccion que tomará el proyectil
    //uso de señales y slots
    QPixmap getProyectil();
public slots: //es una funcion que puede ser asigana a una señal
    void colisiones();
private:
    QPointF direccion;
    qreal velocidad;
    //texturas
    QPixmap proy;
};

#endif // PROYECTIL_H
