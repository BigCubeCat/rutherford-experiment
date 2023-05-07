#include "Particle.hpp"

#define SIZE 10

Particle::Particle(QObject *parent) : QObject(parent), QGraphicsItem() {}

Particle::~Particle() {}

QRectF Particle::boundingRect() const {
    return QRectF(-SIZE, -SIZE, 2 * SIZE, 2 * SIZE);
}

void Particle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget) {
    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawEllipse(-SIZE, -SIZE, 2 * SIZE, 2 * SIZE);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Particle::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    /* Set the position of the graphical element in the graphic scene,
     * translate coordinates of the cursor within the graphic element
     * in the coordinate system of the graphic scenes
     * */
    this->setPos(mapToScene(event->pos()));
}

void Particle::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void Particle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
