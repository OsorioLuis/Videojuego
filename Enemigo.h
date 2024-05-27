#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Personaje.h"
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include "Juego.h"

extern Juego *juego;

class Enemigo : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemigo(int nivel, Personaje *objetivo); //se le pasa el objetivo a seguir
private slots:
    void moverEnemigo();
public:
    void recibirImpacto();
private:
    //miembros de la clase los cuales contienen los punteros de lo que usaremos en los metodos
    Personaje *objetivo;
    QTimer *tiempo;
    int cuentaImpact;
    QPixmap generico;

    //nivel enemigo
    int nivelActual;
};
#endif // ENEMIGO_H
