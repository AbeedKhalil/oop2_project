#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"

class Shooter3 : public Unit {
public:
    Shooter3();
    Shooter3(float spawnX, float spawnY);
    void update() override;
    void render(sf::RenderWindow& window) override;
};

#endif // SOLDIER_H
