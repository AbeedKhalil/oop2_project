#include "EnemyUnit.h"

EnemyUnit::EnemyUnit(float speed, int health, const std::string& texturePath)
    : Unit(speed, health, texturePath) {
    // Additional initialization if needed
}

void EnemyUnit::update() {
    // Basic AI movement and attack logic
    // Example: move left
    m_Sprite.move(-m_Speed * 0.1f, 0);
    // Add attack logic here
}

void EnemyUnit::render(sf::RenderWindow& window) {
    Unit::render(window);
}

void EnemyUnit::attack(Unit* target) {
    if (target && target->isAlive()) {
        target->takeDamage(10); // Example damage value
    }
}
