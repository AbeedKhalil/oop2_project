#include "EnemyUnit.h"

EnemyUnit::EnemyUnit(float speed, int health, int damage, float attackRange, int goldWorth, const std::string& texturePath, float width, float height, float spacing)
    : Unit(speed, health, damage, attackRange, goldWorth, texturePath, width, height, spacing) {
}

EnemyUnit::EnemyUnit(float speed, int health, int damage, float attackRange, int goldWorth, const std::string& texturePath, float spawnX, float spawnY, float width, float height, float spacing)
    : Unit(speed, health, damage, attackRange, goldWorth, texturePath, spawnX, spawnY, width, height, spacing) {
}

void EnemyUnit::update() {
    // Specific enemy unit update logic
    Unit::update(); // Call base class update
}

void EnemyUnit::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
