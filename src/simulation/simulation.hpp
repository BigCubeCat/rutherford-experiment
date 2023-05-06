#pragma once

#include <vector>

const double pi = 3.141592653589793238463;

typedef struct Point {
    double x, y;
} TPoint;

typedef struct ParticleObject {
    TPoint Direction;
    TPoint Position;
} TParticle;

class Simulation {
  public:
    Simulation();
    void Tick();
    void UpdateParticle(int index);

    // Позиция пушки (по x) с альфа-частицами
    float GunPosition = 0;

    // Data about Particles
    int CountParticles;
    std::vector<TPoint> Directions;
    std::vector<TPoint> Positions;
    TPoint AurumPosition;

  private:
    TPoint RandomDirection();
    bool CheckInLimit(int index);
    bool NearAurum(int index);

    double k = 1 / (4 * pi * 8.85e-12);
    double e = 1.6e-19;
    double alpha_q = 2 * e;
    double alpha_m = 6.64456e-27;
    double au_q = 79 * e;
    double au_d = 1e-14;
    double tmp;
    double h;
    double dt;
};
