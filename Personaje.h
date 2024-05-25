#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QVector2D>

class Personaje: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT //necesario para usar slots
public:
    Personaje();
    QPointF getDireccion(); //se usará para saber la direccion del personaje
    void disparar();

protected:
    void keyPressEvent(QKeyEvent * event) override;
    void keyReleaseEvent(QKeyEvent * event) override;
    void actualizarPosicion();
private:
    QPointF direccion;
    qreal velocidad;
    bool arriba = false;
    bool abajo = false;
    bool derecha = false;
    bool izquierda = false;
    QSet<int> teclas;
    QTimer *tempo;

    //texturas
    QPixmap normal;
    QPixmap der;
    QPixmap izq;
    QPixmap abj;
    QPixmap arr;

};

#endif // PERSONAJE_H
