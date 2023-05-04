#include "./simulation.h"
#include <cmath>
#include <cstdlib>

Simulation GetSimulation() {
    Simulation sim;
    sim.tmp = sim.k * sim.alpha_q * sim.alpha_m;
    return sim;
}

TPoint RandomDirection() {
    double x = (rand() % 2) * (rand() % 2 == 0 ? -1 : 1);
    double y = (rand() % 2) * (rand() % 2 == 0 ? -1 : 1);
    return TPoint{x, y};
}

double VectorSize(double x, double y) { return sqrt(x * x + y * y); }

TPoint UpdateParticle(Simulation sim, TPoint point, TPoint au) {
    TPoint direction;
    direction.x = sim.tmp * (point.x - au.x) /
                  pow(VectorSize(point.x - au.x, point.y - au.y), 3);
    direction.y = sim.tmp * (point.y - au.y) /
                  pow(VectorSize(point.x - au.x, point.y - au.y), 3);
    return direction;
}
