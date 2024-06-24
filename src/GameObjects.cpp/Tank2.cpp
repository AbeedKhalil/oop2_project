#include "Tank2.h"
#include "Constants.h"

Tank2::Tank2() : Unit(2.0f, 300, "skeleton10-Idle_0.png", TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT) {
    // Additional initialization if needed
}

Tank2::Tank2(float spawnX, float spawnY) : Unit(2.0f, 300, "skeleton10-Idle_0.png", spawnX, spawnY, TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT) {
    // Additional initialization if needed
}

void Tank2::update() {
    // Specific tank update logic
    Unit::update(); // Call base class update
}

void Tank2::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
