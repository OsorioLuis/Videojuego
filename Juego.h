#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsView>
#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>
#include <QObject>
#include "Personaje.h"
#include "Puntuacion.h"

class Juego: public QGraphicsView{
    Q_OBJECT
public:
    explicit Juego(QWidget * parent = nullptr);

    //setters de dificultad
    void establecerNivel(int nivel);
    int getNivelActual();
    Puntuacion *ptsJugador;
public slots:
    void crearEnemigo();
    void actualizarVida(int nuevaVida);
    void mostrarImagenMuerte();
private:
    QGraphicsScene * escena;
    Personaje * personaje;
    QTimer *tiempo;
    QGraphicsTextItem *vidaTexto;
    QGraphicsTextItem *nivelJuego;

    //imagen muerte
    QGraphicsPixmapItem *muerte;

    //datos para definir dificultad
    int nivelActual;
    //luego se instanciaran los respectivos datos de ataque, vida etc
};

#endif // JUEGO_H
