#include "Tank3.h"
#include "Constants.h"

Tank3::Tank3() : Unit(1.0f, TANK_3_HEALTH, TANK_3_DAMAGE, 10, TANK_3_WORTH, "Tank.png", TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT, TANK_3_SPACING) {
    // Additional initialization if needed
}

Tank3::Tank3(float spawnX, float spawnY) : Unit(1.0f, TANK_3_HEALTH, TANK_3_DAMAGE, 10, TANK_3_WORTH, "Tank.png", spawnX, spawnY, TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT, TANK_3_SPACING) {
    // Additional initialization if needed
}

void Tank3::update() {
    // Specific tank update logic
    Unit::update(); // Call base class update
}

void Tank3::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
