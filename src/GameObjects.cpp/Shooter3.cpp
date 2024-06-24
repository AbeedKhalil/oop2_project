#include "Shooter3.h"
#include "Constants.h"

Shooter3::Shooter3() : Unit(1.0f, 100, "soldier.png", SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT) {
    // Additional initialization if needed
}

Shooter3::Shooter3(float spawnX, float spawnY) : Unit(1.0f, 100, "soldier.png", spawnX, spawnY + 25, SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT) {
    // Additional initialization if needed
}

void Shooter3::update() {
    // Specific soldier update logic
    Unit::update(); // Call base class update
}

void Shooter3::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
