#include "./simulation.hpp"
#include <cmath>
#include <iostream>

#define LEFT_LIMIT -3e-13
#define RIGHT_LIMIT 5e-13

double randZeroToOne() { return rand() / (RAND_MAX + 1.); }
double VectorSize(double x, double y) { return sqrt(x * x + y * y); }

Simulation::Simulation() {
    // Предподсчитываем значение
    tmp = k * au_q * alpha_q * dt / alpha_m;
    AurumPosition = TPoint{au_d * -10, 0};
}

bool Simulation::NearAurum(int index) {
    double x = AurumPosition.x - Positions[index].x;
    double y = AurumPosition.y - Positions[index].y;
    double length = VectorSize(x, y);
    if (length <= 1e-14) {
        std::cout << "shit\n";
    }
    return length <= 1e-10;
}

TPoint Simulation::RandomDirection() {
    double x = 0; // randZeroToOne() * (rand() % 2 == 0 ? -1 : 1);
    double y = 1; // randZeroToOne() * (rand() % 2 == 0 ? -1 : 1);
    return TPoint{x, y};
}

void Simulation::Tick() {
    for (int i = CountParticles; i >= 0; --i) {
        this->UpdateParticle(i);
    }
}

bool Simulation::CheckInLimit(int index) {
    if (Positions[index].x < LEFT_LIMIT && Positions[index].x >= RIGHT_LIMIT) {
        return false;
    }
    if (Positions[index].y < LEFT_LIMIT && Positions[index].y >= RIGHT_LIMIT) {
        return false;
    }
    return true;
}

void Simulation::UpdateParticle(int index) {
    TPoint oldDirection = TPoint{Directions[index].x, Directions[index].y};
    double vec = pow(VectorSize(Positions[index].x, Positions[index].y), 3);

    Directions[index].x += h * tmp * Positions[index].x / vec;
    Directions[index].y += h * tmp * Positions[index].y / vec;

    Positions[index].x += (h / 2) * (oldDirection.x + Directions[index].x) * dt;
    Positions[index].y += (h / 2) * (oldDirection.y + Directions[index].y) * dt;

    if (!CheckInLimit(index)) {
        Positions.erase(Positions.begin() + index);
        Directions.erase(Directions.begin() + index);
        CountParticles--;
    }
}

void Simulation::AddParticle(double xPosition) {
    TPoint position = TPoint{xPosition, -(10 * au_d)};
    TPoint direction = TPoint{0, 1e7};

    Directions.push_back(direction);
    Positions.push_back(position);
}

void Simulation::SetDt(double newDt) { this->dt = newDt; }
