#include "Unit.h"
#include "TextureManager.h"
#include "Constants.h"

Unit::Unit(float speed, int health, const std::string& texturePath, float width, float height)
    : m_Speed(speed), m_Health(health), m_Texture(TextureManager::getInstance().getTexture(texturePath)), m_UnitInFront(nullptr) {
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setPosition(SPAWN_POSITION_X, SPAWN_POSITION_Y);
    setTextureSize(width, height);
}

Unit::Unit(float speed, int health, const std::string& texturePath, float spawnX, float spawnY, float width, float height)
    : m_Speed(speed), m_Health(health), m_Texture(TextureManager::getInstance().getTexture(texturePath)), m_UnitInFront(nullptr) {
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setPosition(spawnX, spawnY);
    setTextureSize(width, height);
}

void Unit::setTextureSize(float width, float height) {
    sf::Vector2u textureSize = m_Texture.getSize();
    float scaleX = width / textureSize.x;
    float scaleY = height / textureSize.y;
    m_Sprite.setScale(scaleX, scaleY);
}

void Unit::update() {
    followUnitInFront();
    move();
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

void Unit::setUnitInFront(Unit* unit) {
    m_UnitInFront = unit;
}

void Unit::followUnitInFront() {
    if (m_UnitInFront != nullptr) {
        // Adjust speed to match the unit in front if close enough
        sf::Vector2f frontPos = m_UnitInFront->m_Sprite.getPosition();
        if (m_Sprite.getPosition().x < frontPos.x - 120) {  // 120 is an example gap, adjust as needed
            m_Speed = m_UnitInFront->m_Speed;
        }
    }
}

void Unit::move() {
    // Basic movement logic
    m_Sprite.move(m_Speed * 0.1f, 0); // Move right
}
