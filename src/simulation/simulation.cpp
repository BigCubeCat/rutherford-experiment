#include "./simulation.hpp"
#include "../utils/utils.hpp"

#include <cmath>
#include <iostream>

#include <QGraphicsScene>

#define LEFT_LIMIT -30e-13
#define RIGHT_LIMIT 30e-13
#define NEAR_RADIUS 10e-15

double VectorSize(TPoint vec) { return sqrt(vec.x * vec.x + vec.y * vec.y); }
TPoint Normalize(TPoint vector) {
    double len = VectorSize(vector);
    return TPoint{vector.x / len, vector.y / len};
}
TPoint ScaleVec(TPoint vec, double scale) {
    return TPoint{vec.x * scale, vec.y * scale};
}
TPoint SumVec(TPoint a, TPoint b) { return TPoint{a.x + b.x, a.y + b.y}; }

Simulation::Simulation(QGraphicsScene *scene) {
    // Предподсчитываем значение
    AurumPosition = TPoint{0, 0};
    this->scene = scene;
}

bool Simulation::NearAurum(int index) {
    double x = AurumPosition.x - Positions[index].x;
    double y = AurumPosition.y - Positions[index].y;
    double length = VectorSize(TPoint{x, y});
    return length <= NEAR_RADIUS;
}

void Simulation::Tick() {
    for (int i = CountParticles - 1; i >= 0; --i) {
        this->UpdateParticle(i);
    }
}

bool Simulation::CheckInLimit(int index) {
    if (Positions[index].x < LEFT_LIMIT || Positions[index].x >= RIGHT_LIMIT) {
        return false;
    }
    if (Positions[index].y < LEFT_LIMIT || Positions[index].y >= RIGHT_LIMIT) {
        return false;
    }
    return true;
}

void Simulation::RemoveParticle(int index) {
    scene->removeItem(ParticleItems[index]);
    ParticleItems.erase(ParticleItems.begin() + index);
    Positions.erase(Positions.begin() + index);
    Directions.erase(Directions.begin() + index);
    CountParticles--;
}

void Simulation::UpdateParticle(int index) {
    if (NearAurum(index)) {
        TPoint pos = Positions[index];
        TPoint direction = Directions[index];

        TPoint forceDirection =
            TPoint{pos.x - AurumPosition.x, pos.y - AurumPosition.y};

        double force = tmp * dt / VectorSize(forceDirection);

        Directions[index] = SumVec(
            Directions[index], ScaleVec(Normalize(forceDirection), force * dt));
    }
    Positions[index] = SumVec(Positions[index], Directions[index]);
    if (!CheckInLimit(index)) {
        RemoveParticle(index);
    }
}

void Simulation::AddParticle(Particle *particaleItem) {
    double yPos = (double)randrange(5, 10) / 10 * 30e-14;
    double xPos = randrange(-this->slotWidth, this->slotWidth) * 1e-15;
    TPoint position = TPoint{xPos, yPos};
    TPoint direction = TPoint{0, -1e-14};

    Directions.push_back(direction);
    Positions.push_back(position);
    ParticleItems.push_back(particaleItem);

    CountParticles++;
}
