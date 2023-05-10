#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QPainter>

#include "../Particle/Particle.hpp"
#include "../simulation/simulation.hpp"

typedef struct TIntPoint {
    int x, y;
} TIntPoint;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Simulation *simulation;
    std::vector<Particle *> Particles;

  private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;

    TIntPoint ToViewPoint(TPoint point);
  private slots:
    void AddParticle();
    void UpdateRender();
};
#endif // MAINWINDOW_H
