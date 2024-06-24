#include "Castle.h"

Castle::Castle(const std::string& texturePath, float x, float y) : m_Health(1000) {  // Example health
    m_Texture = &TextureManager::getInstance().getTexture(texturePath);
    m_Sprite.setTexture(*m_Texture);
    m_Sprite.setPosition(x, y);

    // Set the scale to make the castle smaller
    float scale = 0.55f;  // Adjust the scale factor as needed
    m_Sprite.setScale(scale, scale);
}

void Castle::render(sf::RenderWindow& window) {
    window.draw(m_Sprite);
}

void Castle::takeDamage(int damage) {
    m_Health -= damage;
    if (m_Health < 0) {
        m_Health = 0;
    }
}

bool Castle::isDestroyed() const {
    return m_Health <= 0;
}

void Castle::setScale(float x, float y) {
    m_Sprite.setScale(x, y);
}
