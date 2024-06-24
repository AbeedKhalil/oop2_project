#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"

class Shooter2 : public Unit {
public:
    Shooter2();
    Shooter2(float spawnX, float spawnY);
    void update() override;
    void render(sf::RenderWindow& window) override;
};

#endif // SOLDIER_H
