#include "Tank3.h"
#include "Constants.h"

Tank3::Tank3() : Unit(2.0f, 300, "Tank.png", TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT) {
    // Additional initialization if needed
}

Tank3::Tank3(float spawnX, float spawnY) : Unit(2.0f, 300, "Tank.png", spawnX, spawnY, TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT) {
    // Additional initialization if needed
}

void Tank3::update() {
    // Specific tank update logic
    Unit::update(); // Call base class update
}

void Tank3::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
