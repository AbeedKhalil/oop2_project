#ifndef SHOOTER1_H
#define SHOOTER1_H

#include "Unit.h"

class Shooter1 : public Unit {
public:
    // Constructors
    Shooter1();
    Shooter1(float spawnX, float spawnY);

    // Override methods
    void update() override;
    void render(sf::RenderWindow& window) override;
};

#endif // SHOOTER1_H