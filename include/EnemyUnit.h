#ifndef ENEMYUNIT_H
#define ENEMYUNIT_H

#include "Unit.h"

class EnemyUnit : public Unit {
public:
    EnemyUnit(float speed, int health, const std::string& texturePath);
    void update() override;
    void render(sf::RenderWindow& window) override;
    void attack(Unit* target);
};

#endif // ENEMYUNIT_H
