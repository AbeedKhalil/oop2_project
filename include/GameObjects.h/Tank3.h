#ifndef TANK3_H
#define TANK3_H

#include "Unit.h"

class Tank3 : public Unit {
public:
    // Constructors
    Tank3();
    Tank3(float spawnX, float spawnY);

    // Override methods
    void update() override;
    void render(sf::RenderWindow& window) override;
};

#endif // TANK3_H