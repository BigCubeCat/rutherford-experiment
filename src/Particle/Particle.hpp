#ifndef PARTICLE_H
#define PARTICLE_H

#include <QCursor>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QPainter>

class Particle : public QObject, public QGraphicsItem {
    Q_OBJECT
  public:
    explicit Particle(QObject *parent = 0, bool isAlpha = true);
    ~Particle();
    int color[3];
    int size;

  private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

  private:
    void KeyPressEvent(QKeyEvent *event);
};

#endif // PARTICLEVIEW_H
