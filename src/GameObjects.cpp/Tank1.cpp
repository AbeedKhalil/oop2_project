#include "Tank1.h"
#include "Constants.h"

Tank1::Tank1() : Unit(15.0f, TANK_1_HEALTH, TANK_1_DAMAGE, 10, TANK_1_WORTH, "Tank.png", TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT, TANK_1_SPACING) {
    // Additional initialization if needed
}

Tank1::Tank1(float spawnX, float spawnY) : Unit(15.0f, TANK_1_HEALTH, TANK_1_DAMAGE, 10, TANK_1_WORTH, "Tank.png", spawnX, spawnY, TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT, TANK_1_SPACING) {
    // Additional initialization if needed
}

void Tank1::update() {
    // Specific tank update logic
    Unit::update(); // Call base class update
}

void Tank1::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
