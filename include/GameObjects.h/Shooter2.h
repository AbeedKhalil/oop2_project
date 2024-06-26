#ifndef SHOOTER2_H
#define SHOOTER2_H

#include "Unit.h"

class Shooter2 : public Unit {
public:
    // Constructors
    Shooter2();
    Shooter2(float spawnX, float spawnY);

    // Override methods
    void update() override;
    void render(sf::RenderWindow& window) override;
};

#endif // SHOOTER2_H