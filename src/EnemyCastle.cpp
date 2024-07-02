#include "EnemyCastle.h"

EnemyCastle::EnemyCastle(const std::string& texturePath, float x, float y)
    : Castle(texturePath, x, y) {
    // Adjust the position to ensure the castle stays in the correct location
    sf::Vector2u textureSize = m_Texture->getSize();

    // Update the health bar position
    updateHealthBar();
}

void EnemyCastle::takeDamage(int damage) {
    Castle::takeDamage(damage);  // Call the base class method
}

void EnemyCastle::render(sf::RenderWindow& window) {
    window.draw(m_Sprite);  // Render the sprite
    renderHealthBar(window);  // Render the health bar
}