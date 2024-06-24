#ifndef TANK_H
#define TANK_H

#include "Unit.h"

class Tank1 : public Unit {
public:
    Tank1();
    Tank1(float spawnX, float spawnY);
    void update() override;
    void render(sf::RenderWindow& window) override;
};

#endif // TANK_H
