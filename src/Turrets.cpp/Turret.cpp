#include "Turret.h"

Turret::Turret(float damage, float range, float fireRate, const std::string& texturePath, float x, float y)
    : m_Damage(damage), m_Range(range), m_FireRate(fireRate) {
    m_Sprite.setTexture(TextureManager::getInstance().getTexture(texturePath));
    m_Sprite.setPosition(x, y);

    // Adjust this scale factor to make the turrets smaller
    float scaleFactor = 0.3f; // You can adjust this value as needed
    m_Sprite.setScale(scaleFactor, scaleFactor);
}
void Turret::update() {
    // Implement turret logic here (e.g., finding targets)
}

void Turret::render(sf::RenderWindow& window) {
    window.draw(m_Sprite);
}

bool Turret::canFire() const {
    return m_FireClock.getElapsedTime().asSeconds() >= 1.0f / m_FireRate;
}

void Turret::fire() {
    // Implement firing logic here
    m_FireClock.restart();
}