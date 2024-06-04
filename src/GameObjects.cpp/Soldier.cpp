#include "Soldier.h"

Soldier::Soldier() : Unit(50.0f, 100, "bullet.png") {
    // Additional initialization if needed
}

void Soldier::update() {
    // Specific soldier update logic
    Unit::update(); // Call base class update
}

void Soldier::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
