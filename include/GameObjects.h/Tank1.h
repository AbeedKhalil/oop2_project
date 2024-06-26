#ifndef TANK1_H
#define TANK1_H

#include "Unit.h"

class Tank1 : public Unit {
public:
    // Constructors
    Tank1();
    Tank1(float spawnX, float spawnY);

    // Override methods
    void update() override;
    void render(sf::RenderWindow& window) override;
};

#endif // TANK1_H