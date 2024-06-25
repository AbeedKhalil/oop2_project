#include "EnemyCastle.h"

EnemyCastle::EnemyCastle(const std::string& texturePath, float x, float y)
    : Castle(texturePath, x, y) {
    // Adjust the position to ensure the castle stays in the correct location
    sf::Vector2u textureSize = m_Texture->getSize();
}

void EnemyCastle::render(sf::RenderWindow& window) {
    window.draw(m_Sprite);  // Render the sprite
}