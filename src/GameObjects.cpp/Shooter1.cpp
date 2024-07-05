#include "Shooter1.h"

Shooter1::Shooter1() : Unit(SHOOTER_1_SPEED, SHOOTER_1_HEALTH, SHOOTER_1_DAMAGE, SHOOTER_1_ATTACK_RANGE, SHOOTER_1_WORTH, "skeleton1-Idle_0.png", SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT, SHOOTER_1_SPACING) {
    // Additional initialization if needed
}

Shooter1::Shooter1(float spawnX, float spawnY) : Unit(SHOOTER_1_SPEED, SHOOTER_1_HEALTH, SHOOTER_1_DAMAGE, SHOOTER_1_ATTACK_RANGE, SHOOTER_1_WORTH, "skeleton1-Idle_0.png", spawnX, spawnY + 25, SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT, SHOOTER_1_SPACING) {
    // Additional initialization if needed
}

void Shooter1::update() {
    // Specific soldier update logic
    Unit::update(); // Call base class update
}

void Shooter1::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}

void Shooter1::playShootSound() {
    SoundManager::getInstance().playSound("shoot");
}