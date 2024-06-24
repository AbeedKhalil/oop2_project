#include "Shooter2.h"
#include "Constants.h"

Shooter2::Shooter2() : Unit(1.0f, 100, "soldier.png", SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT) {
    // Additional initialization if needed
}

Shooter2::Shooter2(float spawnX, float spawnY) : Unit(1.0f, 100, "soldier.png", spawnX, spawnY + 25, SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT) {
    // Additional initialization if needed
}

void Shooter2::update() {
    // Specific soldier update logic
    Unit::update(); // Call base class update
}

void Shooter2::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
