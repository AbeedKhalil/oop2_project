#include "Tank.h"
#include "Constants.h"

Tank::Tank() : Unit(2.0f, 300, "Tank.png", TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT) {
    // Additional initialization if needed
}

Tank::Tank(float spawnX, float spawnY) : Unit(2.0f, 300, "Tank.png", spawnX, spawnY, TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT) {
    // Additional initialization if needed
}

void Tank::update() {
    // Specific tank update logic
    Unit::update(); // Call base class update
}

void Tank::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
