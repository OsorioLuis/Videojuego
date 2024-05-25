#include <QApplication>
#include <QGraphicsScene>
//#include <QGraphicsRectItem>
#include "Juego.h"
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
    Juego juego;
    juego.show();

    return a.exec();
}
