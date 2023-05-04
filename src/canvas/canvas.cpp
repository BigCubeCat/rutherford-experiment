#include "./canvas.h"
#include <QDebug>
#include <QKeyEvent>
#include <QPainter>

#define SPEED 1
#define SIZE 40
#define AU_SIZE 20

const double PI  =3.141592653589793238463;

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    setBackgroundRole(QPalette::Base);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Canvas::tick);
    timer->start(100);
}

void Canvas::tick() {
}

Canvas::~Canvas(){};

void Canvas::paintEvent(QPaintEvent *e) {
    QPainter painter(this);

    setAutoFillBackground(true);

    // draw particle gun
    painter.drawRect(scene.GunPosition + this->width() / 2,
                     this->height() - SIZE - 1, SIZE, SIZE);

    // Draw gold

    painter.setBrush(QBrush(Qt::red));
    painter.setPen(QPen(Qt::blue));
    painter.drawEllipse(this->width() / 2, this->height() / 2 - AU_SIZE,
                        SIZE / 2, SIZE / 2);
}

void Canvas::SpawnParticle() {
    TPoint dir = RandomDirection();
    scene.Particles.push_back(TParticle{dir, TPoint{scene.GunPosition, 0}});
    scene.CountParticles++;
}

void Canvas::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        scene.GunPosition = max(scene.GunPosition - SPEED, -width() / 2);
    }
    if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        scene.GunPosition = min(scene.GunPosition + SPEED, width() / 2 - SIZE);
    }
    if (event->key() == Qt::Key_Space) {
        SpawnParticle();
    }
    update();
}
