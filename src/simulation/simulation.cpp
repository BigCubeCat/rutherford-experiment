#include "./simulation.hpp"
#include "../utils/utils.hpp"

#include <cmath>
#include <iostream>

#include <QGraphicsScene>
#include <math.h>

#define LEFT_LIMIT -30e-14 - 1e-15
#define RIGHT_LIMIT 30e-14 + 1e-15
#define NEAR_RADIUS 10e-15

int getIndex(int i) {
    if (i <= 5) {
        return 0;
    } else if (i <= 15) {
        return 1;
    } else if (i <= 60) {
        return 2;
    }
    return 3;
}

double VectorSize(TPoint vec) { return sqrt(vec.x * vec.x + vec.y * vec.y); }

double GetAngle(TPoint start, TPoint finish) {
    double tangens = (start.x - finish.x) / (finish.y - start.y);
    if (finish.y > 0) {
        // Улетела назад
        return 180;
    }
    return atan(tangens) * 180 / pi;
}
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
    for (int i = 0; i < 4; ++i) {
        this->percents[i] = 0;
        this->statistic[i] = 0;
    }
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
    // Write statistic
    int i = (int)(GetAngle(StartPos[index], Positions[index]));
    int indx = getIndex(i);
    statistic[indx]++;
    countDestroyed++;
    percents[indx] = ((float)statistic[indx] / (float)countDestroyed) * 100;

    // Remove particle
    scene->removeItem(ParticleItems[index]);
    ParticleItems.erase(ParticleItems.begin() + index);
    Positions.erase(Positions.begin() + index);
    Directions.erase(Directions.begin() + index);
    StartPos.erase(StartPos.begin() + index);
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
    double yPos = (double)randrange(8, 10) / 10 * 30e-14;
    double xPos = randrange(-this->slotWidth, this->slotWidth) * 1e-15;
    TPoint position = TPoint{xPos, yPos};
    TPoint direction = TPoint{0, -1e-14};

    Directions.push_back(direction);
    Positions.push_back(position);
    StartPos.push_back(position);
    ParticleItems.push_back(particaleItem);

    CountParticles++;
}

void Simulation::Reset() {
    for (int i = 0; i < 4; ++i) {
        this->percents[i] = 0;
        this->statistic[i] = 0;
    }
    this->countDestroyed = 0;
}
