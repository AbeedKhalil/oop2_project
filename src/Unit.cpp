#include "Unit.h"

Unit::Unit(float speed, int health, const std::string& texturePath)
    : m_Speed(speed), m_Health(health) {
    m_Texture.loadFromFile(texturePath);
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setPosition(100, 100); // Example position
}

void Unit::update() {
    // Basic movement logic
    m_Sprite.move(m_Speed * 0.1f, 0); // Move right
    // Add combat and health update logic here
}

void Unit::render(sf::RenderWindow& window) {
    window.draw(m_Sprite);
}

void Unit::takeDamage(int damage) {
    m_Health -= damage;
    if (m_Health < 0) m_Health = 0;
}

bool Unit::isAlive() const {
    return m_Health > 0;
}
