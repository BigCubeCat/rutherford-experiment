#include <QPushButton>
#include <QTimer>

#include "../Particle/Particle.hpp"
#include "./mainwindow.hpp"
#include "./ui_mainwindow.h"

#define SIZE 10

static int randomBetween(int low, int high) {
    return (rand() % ((high + 1) - low) + low);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::UpdateRender);
    timer->start(1000);

    this->resize(640, 640);

    // this->setFixedSize(640, 640);

    scene = new QGraphicsScene(this); // Init graphics scene
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    ui->graphicsView->resize(600, 600);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(
        QGraphicsView::BoundingRectViewportUpdate);

    this->simulation = new Simulation(scene);

    Particle *item = new Particle();
    TIntPoint pnt = ToViewPoint(simulation->AurumPosition);
    qDebug() << "Aurum pos" << pnt.x << " " << pnt.y;
    item->setPos(pnt.x, pnt.y);
    scene->addItem(item);

    connect(ui->addButton, &QPushButton::clicked, this,
            &MainWindow::AddParticle);

    this->setWindowTitle(tr("Опыт Резерфорда"));
}

void MainWindow::UpdateRender() {
    simulation->Tick();
    for (int i = simulation->CountParticles - 1; i >= 0; --i) {
        TIntPoint pnt = ToViewPoint(simulation->Positions[i]);
        qDebug() << i << " x: " << simulation->Positions[i].x << " "
                 << simulation->Positions[i].y;
        Particles[i]->setPos(pnt.x * 10, pnt.y * 10);
    }
}

void MainWindow::AddParticle() {
    Particle *newParticle = new Particle();
    this->Particles.push_back(newParticle);
    scene->addItem(newParticle);
    simulation->AddParticle(newParticle, 1e-14);
}

TIntPoint MainWindow::ToViewPoint(TPoint point) {
    TIntPoint result;
    result.x = point.x * 1e15;
    result.y = point.y * 1e15;
    return result;
}

MainWindow::~MainWindow() { delete ui; }
