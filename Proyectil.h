#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <QGraphicsRectItem>
#include <QObject>

class Proyectil: public QObject, public QGraphicsRectItem{
    //macro
    Q_OBJECT
public:
    Proyectil(); //constructor
    //uso de señales y slots
public slots: //es una funcion que puede ser asigana a una señal
    void moverseUP();
};

#endif // PROYECTIL_H
