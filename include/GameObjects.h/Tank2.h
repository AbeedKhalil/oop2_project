#ifndef TANK2_H
#define TANK2_H

#include "Unit.h"

class Tank2 : public Unit {
public:
    // Constructors
    Tank2();
    Tank2(float spawnX, float spawnY);

    // Override methods
    void update() override;
    void render(sf::RenderWindow& window) override;
};

#endif // TANK2_H