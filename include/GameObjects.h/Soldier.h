#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"

class Soldier : public Unit {
public:
    Soldier();
    void update() override;
    void render(sf::RenderWindow& window) override;
};

#endif // SOLDIER_H
