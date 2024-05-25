#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>
#include <QObject>
#include "Personaje.h"

class Juego: public QGraphicsView{
    Q_OBJECT
public:
    explicit Juego(QWidget * parent = nullptr);
public slots:
    void crearEnemigo();
private:
    QGraphicsScene * escena;
    Personaje * personaje;
    QTimer *tiempo;

    //luego se instanciaran los respectivos datos de ataque, vida etc
};

#endif // JUEGO_H
