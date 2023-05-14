#include <QPushButton>
#include <QTimer>

#include "../Particle/Particle.hpp"
#include "./mainwindow.hpp"
#include "./ui_mainwindow.h"
#include "qgraphicsitem.h"

#define SIZE 5

static int randomBetween(int low, int high) {
    return (rand() % ((high + 1) - low) + low);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    timer = new QTimer(this);
    spawnTimer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::UpdateRender);
    connect(spawnTimer, &QTimer::timeout, this, &MainWindow::SpawnParticles);
    timer->start(10);
    spawnTimer->start(100);

    this->resize(800, 600);
    scene = new QGraphicsScene(this); // Init graphics scene
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-250, -250, 500, 500);

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
    item->color[0] = 128;
    item->color[1] = 128;
    item->color[2] = 32;
    scene->addItem(item);
    Particle *lt = new Particle();

    connect(ui->addButton, &QPushButton::clicked, this,
            &MainWindow::TogglePaused);

    this->setWindowTitle(tr("Опыт Резерфорда"));
}

void MainWindow::UpdateRender() {
    simulation->Tick();
    for (int i = simulation->CountParticles - 1; i >= 0; --i) {
        TIntPoint pnt = ToViewPoint(simulation->Positions[i]);
        qDebug() << i << " x: " << pnt.x << " " << pnt.y;
        Particles[i]->setPos(pnt.x * 10, pnt.y * 10);
    }
}

void MainWindow::SpawnParticles() {
    if (isPaused)
        return;
    for (int i = 0; i < simulation->StreamPower; ++i) {
        Particle *newParticle = new Particle();
        this->Particles.push_back(newParticle);
        scene->addItem(newParticle);
        simulation->AddParticle(newParticle);
    }
}

void MainWindow::TogglePaused() {
    this->isPaused = !this->isPaused;
    ui->addButton->setText(tr((!isPaused) ? "pause" : "run"));
}

TIntPoint MainWindow::ToViewPoint(TPoint point) {
    TIntPoint result;
    double scale = 1e14;
    result.x = point.x * scale;
    result.y = point.y * scale;
    return result;
}

MainWindow::~MainWindow() { delete ui; }
