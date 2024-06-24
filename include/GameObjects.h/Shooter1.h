#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"

class Shooter1 : public Unit {
public:
    Shooter1();
    Shooter1(float spawnX, float spawnY);
    void update() override;
    void render(sf::RenderWindow& window) override;
};

#endif // SOLDIER_H
