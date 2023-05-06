#include "./canvas.h"
#include <QDebug>
#include <QKeyEvent>
#include <QPainter>

#define SPEED 1
#define SIZE 40
#define AU_SIZE 20

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    setBackgroundRole(QPalette::Base);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Canvas::tick);
    timer->start(1);
    InitScene();
}

void Canvas::tick() {
    for (int i = 0; i < scene.CountParticles; ++i) {
        qDebug() << "Direction:";
        qDebug() << scene.Particles[i].Direction.x << " "
                 << scene.Particles[i].Direction.y << "\n";
        qDebug() << "Position:";
        qDebug() << scene.Particles[i].Position.x << " "
                 << scene.Particles[i].Position.y << "\n";
        UpdateParticle(&scene, i);
    }
}

void Canvas::InitScene() { scene.AuPosition = {1e-14, 1e2}; }

void Canvas::SpawnParticle() {
    TPoint dir = RandomDirection();
    qDebug() << "Spawned with direction:";
    qDebug() << dir.x << " " << dir.y << "\n";
    scene.Particles.push_back(TParticle{dir, TPoint{1e-13, 0}});
    scene.CountParticles++;
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
