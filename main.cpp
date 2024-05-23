#include <QApplication>
#include <QGraphicsScene>
//#include <QGraphicsRectItem>
#include "Personaje.h"
#include <QGraphicsView>
#include <QTimer>
#include <QPainter>

/*necesitaremos clases esenciales:
 * QGraphicsScene
 * QGraphicsItem (QGraphicsRectItem)
 * QGraphicsView
 *
 * events (presionar teclas)
 * event propagation system
 * QKeyEvent
 * QDebug (mostrar mensajes en consola)
 *
*/
int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    //Creamos una escena para poner elementos
    QGraphicsScene * escena = new QGraphicsScene();

    //elementos de la escena
    Personaje * item = new Personaje();
    item->setRect(0, 0, 100, 100);
    //hacemos que este elemento sea el que ocasione el evento
    item->setFlag(QGraphicsRectItem::ItemIsFocusable);
    item->setFocus();

    //añadir elemento a escena
    escena->addItem(item);

    //añadir vista
    QGraphicsView * vista = new QGraphicsView(escena);

    //configuracion de escena
    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //en este caso usamos el constructor para añadir la escena a la vista
    vista->show();
    vista->setFixedSize(1280, 720);
    escena->setSceneRect(0,0, 1280, 720); //tanto la vista como la escena tienen
    //las mismas dimensiones
    item->setPos(vista->width()/2.2, vista->height() - 720/1.6);

    //spawn de enemigos
    QTimer * tiempo = new QTimer();
    //modificar item
    QObject::connect(tiempo, SIGNAL(timeout()), item, SLOT(spawn()));
    tiempo->start(2000);

    return a.exec();
}
