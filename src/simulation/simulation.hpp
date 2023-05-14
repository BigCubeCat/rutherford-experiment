#pragma once

#include "../Particle/Particle.hpp"
#include <vector>

const double pi = 3.141592653589793238463;

typedef struct Point {
    double x, y;
} TPoint;

TPoint Normalize(TPoint vector);

class Simulation {
  public:
    Simulation(QGraphicsScene *scene);
    void Tick();
    void Update();
    void UpdateParticle(int index);
    void AddParticle(Particle *particleItem);
    void RemoveParticle(int index);
    int StreamPower = 10; // count particles spawned
    double slotWidth = 100;

    // Data about Particles
    int CountParticles = 0;
    std::vector<TPoint> Directions;
    std::vector<TPoint> Positions;
    std::vector<Particle *> ParticleItems;
    TPoint AurumPosition;

    int statistic[5];

  private:
    bool CheckInLimit(int index);
    bool NearAurum(int index);
    QGraphicsScene *scene;

    double k = 1 / (4 * pi * 8.85e-12);
    double e = 1.6e-19;
    double alpha_q = 2 * e;
    double alpha_m = 6.64456e-27;
    double au_q = 79 * e;
    double au_d = 1e-14;
    double dt = 1e-10;
    double tmp = k * au_q * alpha_q * dt / alpha_m;
    double h = 0.00001;
};
