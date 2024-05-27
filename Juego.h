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

    //setters de dificultad
    void establecerNivel(int nivel);
    int getNivelActual();

    void verificarPuntuacion();
public slots:
    void crearEnemigo();
    void actualizarVida(int nuevaVida);
    void actualizarPuntuacion(int nuevaPts);
    void mostrarImagenMuerte();
private:
    QGraphicsScene * escena;
    Personaje * personaje;
    QTimer *tiempo;
    QGraphicsTextItem *vidaTexto;
    QGraphicsTextItem *nivelJuego;
    QGraphicsTextItem *ptsJugador;
    //imagen muerte
    QGraphicsPixmapItem *muerte;

    //datos para definir dificultad
    int nivel;
    int puntuacionObjetivo;
    QGraphicsTextItem *mensajeNivel;
    int nivelActual;
    //luego se instanciaran los respectivos datos de ataque, vida etc
};

#endif // JUEGO_H
