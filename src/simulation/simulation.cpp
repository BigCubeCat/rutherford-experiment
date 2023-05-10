#include "./simulation.hpp"
#include <cmath>
#include <iostream>

#include <QGraphicsScene>

#define LEFT_LIMIT -5e-13
#define RIGHT_LIMIT 5e-13
#define NEAR_RADIUS 1e-14

double randZeroToOne() { return rand() / (RAND_MAX + 1.); }
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
    if (length <= NEAR_RADIUS) {
        std::cout << "shit\n";
    }
    return length <= NEAR_RADIUS;
}

TPoint Simulation::RandomDirection() {
    double x = 0; // randZeroToOne() * (rand() % 2 == 0 ? -1 : 1);
    double y = 1; // randZeroToOne() * (rand() % 2 == 0 ? -1 : 1);
    return TPoint{x, y};
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
    qDebug() << "REMOVE PARTICLE " << index;
    scene->removeItem(ParticleItems[index]);
    ParticleItems.erase(ParticleItems.begin() + index);
    Positions.erase(Positions.begin() + index);
    Directions.erase(Directions.begin() + index);
    CountParticles--;
}

void Simulation::UpdateParticle(int index) {
    /*
    TPoint oldDirection = TPoint{Directions[index].x, Directions[index].y};
    double vec = pow(VectorSize(Positions[index].x, Positions[index].y), 3);

    Directions[index].x += h * tmp * Positions[index].x / vec;
    Directions[index].y += h * tmp * Positions[index].y / vec;

    Positions[index].x += (h / 2) * (oldDirection.x + Directions[index].x) * dt;
    Positions[index].y += (h / 2) * (oldDirection.y + Directions[index].y) * dt;
    */
    qDebug() << "Update Particle " << index;
    if (NearAurum(index)) {
        qDebug() << "Near Aurum";
        TPoint pos = Positions[index];
        TPoint direction = Directions[index];

        TPoint forceDirection =
            TPoint{pos.x - AurumPosition.x, pos.y - AurumPosition.y};

        double force = tmp * dt / VectorSize(forceDirection);

        Directions[index] = SumVec(
            Directions[index], ScaleVec(Normalize(forceDirection), force * dt));
        qDebug() << "dir: " << Directions[index].x << " "
                 << Directions[index].y;
        std::cout << "dir: " << Directions[index].x << " "
                  << Directions[index].y << std::endl;
    }
    Positions[index] = SumVec(Positions[index], Directions[index]);

    qDebug() << "pos: " << Positions[index].x << " " << Positions[index].y;
    std::cout << "pos: " << Positions[index].x << " " << Positions[index].y
              << std::endl;

    if (!CheckInLimit(index)) {
        RemoveParticle(index);
    }
}

void Simulation::AddParticle(Particle *particaleItem, double xPosition) {
    TPoint position = TPoint{-1e-15, 1e-15};
    TPoint direction = TPoint{0, 0};

    Directions.push_back(direction);
    Positions.push_back(position);
    ParticleItems.push_back(particaleItem);

    CountParticles++;
}

void Simulation::SetDt(double newDt) { this->dt = newDt; }
