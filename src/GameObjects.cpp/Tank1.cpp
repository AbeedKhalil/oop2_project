#include "Tank1.h"
#include "Constants.h"

Tank1::Tank1() : Unit(2.0f, 300, "Tank.png", TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT) {
    // Additional initialization if needed
}

Tank1::Tank1(float spawnX, float spawnY) : Unit(2.0f, 300, "Tank.png", spawnX, spawnY, TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT) {
    // Additional initialization if needed
}

void Tank1::update() {
    // Specific tank update logic
    Unit::update(); // Call base class update
}

void Tank1::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
