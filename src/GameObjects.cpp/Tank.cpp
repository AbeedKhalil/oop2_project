#include "Tank.h"

Tank::Tank() : Unit(30.0f, 300, "bullet.png") {
    // Additional initialization if needed
}

void Tank::update() {
    // Specific tank update logic
    Unit::update(); // Call base class update
}

void Tank::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
