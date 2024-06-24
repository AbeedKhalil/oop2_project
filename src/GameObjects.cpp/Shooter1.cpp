#include "Shooter1.h"
#include "Constants.h"

Shooter1::Shooter1() : Unit(1.0f, 100, "soldier.png", SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT) {
    // Additional initialization if needed
}

Shooter1::Shooter1(float spawnX, float spawnY) : Unit(1.0f, 100, "soldier.png", spawnX, spawnY + 25, SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT) {
    // Additional initialization if needed
}

void Shooter1::update() {
    // Specific soldier update logic
    Unit::update(); // Call base class update
}

void Shooter1::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
