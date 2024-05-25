#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Personaje.h"
#include <QGraphicsRectItem>

class Enemigo : public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemigo(Personaje *objetivo); //se le pasa el objetivo a seguir
private slots:
    void moverEnemigo();
private:
    //miembros de la clase los cuales contienen los punteros de lo que usaremos en los metodos
    Personaje *objetivo;
    QTimer *tiempo;
};
#endif // ENEMIGO_H
