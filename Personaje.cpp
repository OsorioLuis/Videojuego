#include "Personaje.h"
#include "Proyectil.h"
#include "Enemigo.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QKeyEvent>

Personaje::Personaje() : vida(70), puntuacion(0){
    //slot para frecuencia de actualizacion de movimiento
    tempo = new QTimer(this);
    connect(tempo, &QTimer::timeout, this, &Personaje::actualizarPosicion);
    tempo->start(26);

    //slot para manejo de vida
    tiempoCol = new QTimer(this);
    connect(tiempoCol, &QTimer::timeout, this, &Personaje::manejoColision);
    tiempoCol->start(50); //cada 20 ms se verifica si hubo colision

    //direccion inicial de apuntado
    direccion = QPointF(0, -1); //hacia arriba

    normal.load(":/texturas/plaga.png");
    QPixmap scaled = normal.scaled(110,100);

    setPixmap(scaled);
}
void Personaje::reducirVida(int cantidad){
    vida -= cantidad;
    emit vidaCambiada(vida);
    if(vida <= 0){
        emit muerte(); //se envía la señal de que personaje murio
        scene()->removeItem(this);
        delete this;
    }
}
void Personaje::manejoColision(){
    //explicacion:
    //el tipo de datos es una lista de todos los elementos que colisionan
    //con el objeto personaje, en este caso es el creado en esta clase
    //luego se itera por todos los items colisionados y se compara
    //si el tipo dinamico item colisionado es igual al enemigo entonces es porque hubo colision
    QList<QGraphicsItem*> itemsColisionados = collidingItems();
    for(QGraphicsItem *item : itemsColisionados){
        if(typeid(*item) == typeid(Enemigo)){
            reducirVida(1);
        }
    }

}
int Personaje::getVida() const{
    return vida;
}

int Personaje::getPuntacion() const{
    return puntuacion;
}
void Personaje::aumentarPuntuacion(int puntos){
    puntuacion += puntos; //se sumara segun la cantidad de enemigos que elimine
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
    QPixmap scaled = normal.scaled(110,100);
    setPixmap(scaled);
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
    izq.load(":/texturas/izq.png");
    QPixmap scaled_izq = izq.scaled(110,100);
    abj.load(":/texturas/abajo.png");
    QPixmap scaled_abj = abj.scaled(110,100);
    arr.load(":/texturas/arr.png");
    QPixmap scaled_arr = arr.scaled(110,100);
    der.load(":/texturas/der.png");
    QPixmap scaled_der = der.scaled(110,100);


    int movimientoX = 0, movimientoY = 0;
    if (teclas.contains(Qt::Key_Left)) {
        movimientoX -= 10;
        setPixmap(scaled_izq);
    }
    if (teclas.contains(Qt::Key_Right)) {
        movimientoX += 10;
        setPixmap(scaled_der);
    }
    if (teclas.contains(Qt::Key_Up)) {
        movimientoY -= 10;
        setPixmap(scaled_arr);
    }
    if (teclas.contains(Qt::Key_Down)) {
        movimientoY += 10;
        setPixmap(scaled_abj);
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

