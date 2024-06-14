#include "Soldier.h"
#include "Constants.h"

Soldier::Soldier() : Unit(1.0f, 100, "soldier.png", SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT) {
    // Additional initialization if needed
}

Soldier::Soldier(float spawnX, float spawnY) : Unit(1.0f, 100, "soldier.png", spawnX, spawnY + 25, SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT) {
    // Additional initialization if needed
}

void Soldier::update() {
    // Specific soldier update logic
    Unit::update(); // Call base class update
}

void Soldier::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
