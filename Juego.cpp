#include "Juego.h"
#include "Enemigo.h"
#include <QVector2D>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QList>
#include <QGraphicsPixmapItem>
#include <QImage>

Juego::Juego(QWidget * parent) : QGraphicsView(parent){
    //creacion de la escena
    //jerarquia de codigo
    escena = new QGraphicsScene();
    escena->setSceneRect(0,0, 1600, 900);
    setBackgroundBrush(QBrush(QImage(":/texturas/back.png")));

    //imagen muerte
    muerte = new QGraphicsPixmapItem;

    //configuracion de escenas
    setScene(escena);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1600, 900); //para que la vista tenga la misma dimension de la escena

    //creacion de elementos en escena:
    personaje = new Personaje();
    //personaje->setPixmap(normal);
    personaje->setPos(width() / 2, height() / 2); //posicion en el centro


    //establecer valores para aumentar dificultad
    establecerNivel(2);
    //añadir nuevo poder en el nivel 3...

    //creacion textos
    vidaTexto = new QGraphicsTextItem();
    nivelJuego = new QGraphicsTextItem();

    //nivel
    nivelJuego->setPlainText(QString("Nivel: %1").arg(nivelActual));
    nivelJuego->setDefaultTextColor(Qt::white);
    nivelJuego->setFont(QFont("times", 24));
    nivelJuego->setPos(742, 60);
    //vida
    vidaTexto->setPlainText(QString("Vida:%1 | ").arg(personaje->getVida()));
    vidaTexto->setDefaultTextColor(Qt::white);
    vidaTexto->setFont(QFont("times", 15, 1, true));
    vidaTexto->setPos(70, 55);
    //puntuacion
    ptsJugador = new Puntuacion();
    ptsJugador->setPos(150, 55);

    escena->addItem(ptsJugador);
    escena->addItem(nivelJuego);
    escena->addItem(vidaTexto);

    //slots para cambio de vida
    //hacemos la conexion entre la señal vidaCambiada y actualizarVida
    connect(personaje, &Personaje::vidaCambiada, this, &Juego::actualizarVida);
    //player focusable
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();
    //añadimos al jugador en la escena
    escena->addItem(personaje);

    //añadir enemigos
    /*for(int i = 0; i < 10; i++){
        Enemigo *enemigo = new Enemigo(personaje);
        escena->addItem(enemigo);
    }*/
    tiempo = new QTimer(this);
    connect(tiempo, &QTimer::timeout, this, &Juego::crearEnemigo);
    tiempo->start(600); //cambiando este dato podemos definir dificultad

}
void Juego::establecerNivel(int nivel){
    nivelActual = nivel;
}

void Juego::actualizarVida(int nuevaVida){
    vidaTexto->setPlainText(QString("Vida:%1 | ").arg(nuevaVida));
}

void Juego::crearEnemigo(){
    //generacion aleatoria de enemigo
    int randomX = rand() % 1600;
    int randomY= rand() % 900;

    //añadir enemigo a escena
    Enemigo *enemigo = new Enemigo(nivelActual, personaje);
    enemigo->setPos(randomX, randomY);
    escena->addItem(enemigo);
}

