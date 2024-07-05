#ifndef SHOOTER3_H
#define SHOOTER3_H

#include "Unit.h"

class Shooter3 : public Unit {
public:
    // Constructors
    Shooter3();
    Shooter3(float spawnX, float spawnY);

    // Override methods
    void update() override;
    void render(sf::RenderWindow& window) override;
    void playShootSound() override;
};

#endif // SHOOTER3_H