#include "Personaje.h"
#include "Proyectil.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QKeyEvent>

Personaje::Personaje(){
    //slot para frecuencia de actualizacion de movimiento
    tempo = new QTimer(this);
    connect(tempo, &QTimer::timeout, this, &Personaje::actualizarPosicion);
    tempo->start(26);
    //direccion inicial de apuntado
    direccion = QPointF(0, -1); //hacia arriba

    normal.load(":/texturas/plaga.png");
    izq.load(":/texturas/izq.png");
    abj.load(":/texturas/abajo.png");
    arr.load(":/texturas/arr.png");
    der.load(":/texturas/der.png");
    setPixmap(normal);
}


void Personaje::keyPressEvent(QKeyEvent *event)
{
     //para la sobreescritura de las teclas

    //para la deteccion de la direccion a la que apunta personaje
    switch(event->key()){
        case Qt::Key_W:
            arriba = true;

            break;
        case Qt::Key_S:
            abajo = true;

            break;
        case Qt::Key_A:
            izquierda = true;

            break;
        case Qt::Key_D:
            derecha = true;

            break;
        default:
            break;
    }

    //se registra la direccion
    direccion = QPointF(derecha - izquierda, abajo - arriba);
    if (event->key() == Qt::Key_W || event->key() == Qt::Key_S || event->key() == Qt::Key_A || event->key() == Qt::Key_D) {
        disparar();
    }
    teclas.insert(event->key());
    //qDebug() << "Haz presionado una tecla";
}
void Personaje::keyReleaseEvent(QKeyEvent *event){

    switch(event->key()){
    case Qt::Key_W:
        arriba = false;
        break;
    case Qt::Key_S:
        abajo = false;
        break;
    case Qt::Key_A:
        izquierda = false;

        break;
    case Qt::Key_D:
        derecha = false;
        break;
    default:
        break;
    }

    //se registra la direccion
    direccion = QPointF(derecha - izquierda, abajo - arriba);
    teclas.remove(event->key());
    //cuando se deja de presionar la tecla
    setPixmap(normal);
}

QPointF Personaje::getDireccion(){
    return direccion;
}

void Personaje::disparar(){
    Proyectil *proyectil = new Proyectil(direccion);
    //tenemos que añadirlo a la escena
    //posicion del proyectil
    proyectil->setPos(x() + pixmap().width() / 3, y() + pixmap().height() / 3);
    scene()->addItem(proyectil);
}

void Personaje::actualizarPosicion(){
    int movimientoX = 0, movimientoY = 0;
    if (teclas.contains(Qt::Key_Left)) {
        movimientoX -= 10;
        setPixmap(izq);
    }
    if (teclas.contains(Qt::Key_Right)) {
        movimientoX += 10;
        setPixmap(der);
    }
    if (teclas.contains(Qt::Key_Up)) {
        movimientoY -= 10;
        setPixmap(arr);
    }
    if (teclas.contains(Qt::Key_Down)) {
        movimientoY += 10;
        setPixmap(abj);
    }

    //limitar bordes
    //posiciones actuales mas el desplazamiento en pixeles que tuvo
    qreal limiteX = x() + movimientoX;
    qreal limiteY = y() + movimientoY;

    //en caso de que la posicion del rect sea negativa, es decir fuera de las dimensiones de la vista
    if(limiteX < 0) limiteX = 0;
    if(limiteY < 0) limiteY = 0;

    if(limiteX + pixmap().width() > 1600) limiteX = 1600 - pixmap().width();
    if(limiteY + pixmap().height() > 900) limiteY = 900 - pixmap().height();

    // Actualiza la posición del personaje
    if (movimientoX != 0 || movimientoY != 0) {
        setPos(limiteX, limiteY);
    }
}

