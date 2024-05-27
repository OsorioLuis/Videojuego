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
Juego *juego;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    juego = new Juego(); //la clase juegoe es global para que otras clases accedan a este
    juego->show();

    return a.exec();
}
