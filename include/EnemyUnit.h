#ifndef ENEMYUNIT_H
#define ENEMYUNIT_H

#include "Unit.h"

class EnemyUnit : public Unit {
public:
    EnemyUnit(float speed, int health, const std::string& texturePath, float width, float height);
    EnemyUnit(float speed, int health, const std::string& texturePath, float spawnX, float spawnY, float width, float height);
    void update() override;
    void render(sf::RenderWindow& window) override;
};

#endif // ENEMYUNIT_H
