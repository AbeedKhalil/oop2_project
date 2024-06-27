#include "Tank2.h"

Tank2::Tank2() : Unit(TANK_2_SPEED, TANK_2_HEALTH, TANK_2_DAMAGE, TANK_2_ATTACK_RANGE, TANK_2_WORTH, "skeleton10-Idle_0.png", TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT, TANK_2_SPACING) {
    // Additional initialization if needed
}

Tank2::Tank2(float spawnX, float spawnY) : Unit(TANK_2_SPEED, TANK_2_HEALTH, TANK_2_DAMAGE, TANK_2_ATTACK_RANGE, TANK_2_WORTH, "skeleton10-Idle_0.png", spawnX, spawnY, TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT, TANK_2_SPACING) {
    // Additional initialization if needed
}

void Tank2::update() {
    // Specific tank update logic
    Unit::update(); // Call base class update
}

void Tank2::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
