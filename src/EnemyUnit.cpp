#include "EnemyUnit.h"

EnemyUnit::EnemyUnit(float speed, int health, const std::string& texturePath, float width, float height)
    : Unit(speed, health, texturePath, width, height) {
}

EnemyUnit::EnemyUnit(float speed, int health, const std::string& texturePath, float spawnX, float spawnY, float width, float height)
    : Unit(speed, health, texturePath, spawnX, spawnY, width, height) {
}

void EnemyUnit::update() {
    // Specific enemy unit update logic
    Unit::update(); // Call base class update
}

void EnemyUnit::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
