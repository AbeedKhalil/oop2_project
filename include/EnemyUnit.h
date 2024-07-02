#ifndef ENEMYUNIT_H
#define ENEMYUNIT_H

#include "Unit.h"

class EnemyUnit : public Unit {
public:
    // Constructors
    EnemyUnit(float speed, int health, int damage, float attackRange, int goldWorth,
        const std::string& texturePath, float width, float height, float spacing);
    EnemyUnit(float speed, int health, int damage, float attackRange, int goldWorth,
        const std::string& texturePath, float spawnX, float spawnY, float width, float height, float spacing);

    bool isPlayerUnit() const override { return false; }

    // Override methods for enemy-specific behavior
    void update() override;
    void render(sf::RenderWindow& window) override;
    void move() override;
};

#endif // ENEMYUNIT_H