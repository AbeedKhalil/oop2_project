#include "Tank1.h"

Tank1::Tank1() : Unit(TANK_1_SPEED, TANK_1_HEALTH, TANK_1_DAMAGE, TANK_1_ATTACK_RANGE, TANK_1_WORTH, "Tank.png", TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT, TANK_1_SPACING) {
    // Additional initialization if needed
}

Tank1::Tank1(float spawnX, float spawnY) : Unit(TANK_1_SPEED, TANK_1_HEALTH, TANK_1_DAMAGE, TANK_1_ATTACK_RANGE, TANK_1_WORTH, "Tank.png", spawnX, spawnY, TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT, TANK_1_SPACING) {
    // Additional initialization if needed
}

void Tank1::update() {
    // Specific tank update logic
    Unit::update(); // Call base class update
}

void Tank1::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
