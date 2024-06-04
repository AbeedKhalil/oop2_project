#include "Building.h"

Building::Building(const std::string& texturePath, sf::Vector2f position) {
    m_Texture.loadFromFile(texturePath);
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setPosition(position);
}

void Building::render(sf::RenderWindow& window) {
    window.draw(m_Sprite);
}
