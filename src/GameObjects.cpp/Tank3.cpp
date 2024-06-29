#include "Tank3.h"

Tank3::Tank3() : Unit(TANK_3_SPEED, TANK_3_HEALTH, TANK_3_DAMAGE, TANK_3_ATTACK_RANGE, TANK_3_WORTH, "skeleton12-Idle_0.png", TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT, TANK_3_SPACING) {
    // Additional initialization if needed
}

Tank3::Tank3(float spawnX, float spawnY) : Unit(TANK_3_SPEED, TANK_3_HEALTH, TANK_3_DAMAGE, TANK_3_ATTACK_RANGE, TANK_3_WORTH, "skeleton12-Idle_0.png", spawnX, spawnY, TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT, TANK_3_SPACING) {
    // Additional initialization if needed
}

void Tank3::update() {
    // Specific tank update logic
    Unit::update(); // Call base class update
}

void Tank3::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
