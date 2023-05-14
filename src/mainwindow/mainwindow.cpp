#include <QPushButton>
#include <QSlider>
#include <QTimer>

#include "../Particle/Particle.hpp"
#include "./mainwindow.hpp"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle(tr("Опыт Резерфорда"));
    connect(ui->pauseButton, &QPushButton::clicked, this,
            &MainWindow::TogglePaused);
    connect(ui->slotSlider, &QSlider::sliderMoved, this,
            &MainWindow::SlotChange);
    connect(ui->countSlider, &QSlider::sliderMoved, this,
            &MainWindow::StreamChange);

    // setup timers
    timer = new QTimer(this);
    spawnTimer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::UpdateRender);
    connect(spawnTimer, &QTimer::timeout, this, &MainWindow::SpawnParticles);
    timer->start(10);
    spawnTimer->start(500);

    // setup scene
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
    // setup simulation
    this->simulation = new Simulation(scene);
    this->simulation->StreamPower = ui->countSlider->value();
    this->simulation->slotWidth = ui->slotSlider->value();
    Particle *item = new Particle(NULL, false);
    TIntPoint pnt = ToViewPoint(simulation->AurumPosition);
    item->setPos(pnt.x, pnt.y);
    scene->addItem(item);
}

void MainWindow::UpdateRender() {
    simulation->Tick();
    for (int i = simulation->CountParticles - 1; i >= 0; --i) {
        TIntPoint pnt = ToViewPoint(simulation->Positions[i]);
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
    ui->pauseButton->setText(tr((!isPaused) ? "pause" : "run"));
}
void MainWindow::SlotChange() {
    simulation->slotWidth = ui->slotSlider->value();
}
void MainWindow::StreamChange() {
    simulation->StreamPower = ui->countSlider->value();
}

TIntPoint MainWindow::ToViewPoint(TPoint point) {
    TIntPoint result;
    double scale = 1e14;
    result.x = point.x * scale;
    result.y = point.y * scale;
    return result;
}

MainWindow::~MainWindow() { delete ui; }
