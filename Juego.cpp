#include "Juego.h"
#include "Enemigo.h"
#include <QVector2D>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QList>
#include <QGraphicsPixmapItem>

Juego::Juego(QWidget * parent){
    //creacion de la escena
    escena = new QGraphicsScene();
    escena->setSceneRect(0,0, 1600, 900);

    //configuracion de escenas
    setScene(escena);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1600, 900); //para que la vista tenga la misma dimension de la escena

    //creacion de elementos en escena:
    personaje = new Personaje();
    //personaje->setPixmap(normal);
    personaje->setPos(width() / 2, height() / 2); //posicion en el centro

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
};

void Juego::crearEnemigo(){
    //generacion aleatoria de enemigo
    int randomX = rand() % 1600;
    int randomY= rand() % 900;

    //añadir enemigo a escena
    Enemigo *enemigo = new Enemigo(personaje);
    enemigo->setPos(randomX, randomY);
    escena->addItem(enemigo);
}

