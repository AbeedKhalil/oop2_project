#ifndef TANK_H
#define TANK_H

#include "Unit.h"

class Tank2 : public Unit {
public:
    Tank2();
    Tank2(float spawnX, float spawnY);
    void update() override;
    void render(sf::RenderWindow& window) override;
};

#endif // TANK_H
