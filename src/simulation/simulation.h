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

typedef struct Simulation {
    double k = 1 / (4 * pi * 8.85e-12);
    double e = 1.6e-19;
    double alpha_q = 2 * e;
    double alpha_m = 6.64456e-27;
    double au_q = 79 * e;
    double au_d = 1e-14;
    double tmp;
} Simulation;

typedef struct Scene {
    // Позиция пушки (по x) с альфа-частицами
    float GunPosition = 0;
    // Количество частиц
    int CountParticles;
    // Вектор со всеми альфа-частиц
    std::vector<TParticle> Particles;
    TPoint AuPosition;
} TScene;

Simulation GetSimulation();

TPoint RandomDirection();

TPoint UpdateParticle(Simulation sim, TPoint point, TPoint au);
