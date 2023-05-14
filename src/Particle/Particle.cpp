#include "Particle.hpp"

#include "../utils/utils.hpp"

#define SIZE 7
#define AU_SIZE 10

Particle::Particle(QObject *parent, bool isAlpha)
    : QObject(parent), QGraphicsItem() {
    if (isAlpha) {
        size = SIZE;
        color[0] = 128;
        color[1] = 128;
        color[2] = 200;
    } else {
        size = AU_SIZE;
        this->color[0] = 255;
        this->color[1] = 255;
        this->color[2] = 255;
    }
}

Particle::~Particle() {}

QRectF Particle::boundingRect() const {
    return QRectF(-this->size, -this->size, 2 * this->size, 2 * this->size);
}

void Particle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget) {
    painter->setPen(Qt::black);
    painter->setBrush(QColor(color[0], color[1], color[2]));
    painter->drawEllipse(-this->size, -this->size, 2 * this->size,
                         2 * this->size);
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
