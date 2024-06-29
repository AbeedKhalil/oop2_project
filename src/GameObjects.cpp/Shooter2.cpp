#include "Shooter2.h"

Shooter2::Shooter2() : Unit(SHOOTER_2_SPEED, SHOOTER_2_HEALTH, SHOOTER_2_DAMAGE, SHOOTER_2_ATTACK_RANGE, SHOOTER_2_WORTH, "skeleton6-Idle_0.png", SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT, SHOOTER_2_SPACING) {
    // Additional initialization if needed
}

Shooter2::Shooter2(float spawnX, float spawnY) : Unit(SHOOTER_2_SPEED, SHOOTER_2_HEALTH, SHOOTER_2_DAMAGE, SHOOTER_2_ATTACK_RANGE, SHOOTER_2_WORTH, "skeleton6-Idle_0.png", spawnX, spawnY + 25, SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT, SHOOTER_2_SPACING) {
    // Additional initialization if needed
}

void Shooter2::update() {
    // Specific soldier update logic
    Unit::update(); // Call base class update
}

void Shooter2::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
