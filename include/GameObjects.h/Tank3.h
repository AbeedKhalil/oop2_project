#ifndef TANK_H
#define TANK_H

#include "Unit.h"

class Tank3 : public Unit {
public:
    Tank3();
    Tank3(float spawnX, float spawnY);
    void update() override;
    void render(sf::RenderWindow& window) override;
};

#endif // TANK_H
