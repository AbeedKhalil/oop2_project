#ifndef TANK_H
#define TANK_H

#include "Unit.h"

class Tank : public Unit {
public:
    Tank();
    Tank(float spawnX, float spawnY);
    void update() override;
    void render(sf::RenderWindow& window) override;
};

#endif // TANK_H
