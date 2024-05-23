#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsRectItem>
#include <QObject>
class Personaje: public QObject, public QGraphicsRectItem{
    Q_OBJECT //necesario para usar slots
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn(); //esto debe ir en enemigo
};

#endif // PERSONAJE_H
