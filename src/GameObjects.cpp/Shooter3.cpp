#include "Shooter3.h"
#include "Constants.h"

Shooter3::Shooter3() : Unit(50.0f, SHOOTER_3_HEALTH, SHOOTER_3_DAMAGE, 10, SHOOTER_3_WORTH, "soldier.png", SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT, SHOOTER_3_SPACING) {
    // Additional initialization if needed
}

Shooter3::Shooter3(float spawnX, float spawnY) : Unit(50.0f, SHOOTER_3_HEALTH, SHOOTER_3_DAMAGE, 10, SHOOTER_3_WORTH, "soldier.png", spawnX, spawnY + 25, SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT, SHOOTER_3_SPACING) {
    // Additional initialization if needed
}

void Shooter3::update() {
    // Specific soldier update logic
    Unit::update(); // Call base class update
}

void Shooter3::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
