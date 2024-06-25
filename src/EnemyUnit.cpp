#include "EnemyUnit.h"

EnemyUnit::EnemyUnit(float speed, int health, int damage, float attackRange, int goldWorth, const std::string& texturePath, float width, float height, float spacing)
    : Unit(speed, health, damage, attackRange, goldWorth, texturePath, width, height, spacing) {
    // Flip the sprite horizontally
    m_Sprite.setScale(-1.0f, 1.0f);
    // Adjust the origin to make sure the flipped sprite is positioned correctly
    m_Sprite.setOrigin(m_Sprite.getLocalBounds().width, 0);
}

EnemyUnit::EnemyUnit(float speed, int health, int damage, float attackRange, int goldWorth, const std::string& texturePath, float spawnX, float spawnY, float width, float height, float spacing)
    : Unit(speed, health, damage, attackRange, goldWorth, texturePath, spawnX, spawnY, width, height, spacing) {

    // Resize the texture
    setTextureSize(width, height);

    // Flip the sprite horizontally
    m_Sprite.setScale(-m_Sprite.getScale().x, m_Sprite.getScale().y);

    // Adjust the origin to make sure the flipped sprite is positioned correctly
    m_Sprite.setOrigin(m_Sprite.getLocalBounds().width, 0);
}

void EnemyUnit::move() {
    if (m_Sprite.getPosition().x > m_TargetPosition.x) {
        m_Sprite.move(-m_Speed * 0.01f, 0);
    }
    else {
        setState(UnitState::IDLE);
    }
}

void EnemyUnit::update() {
    if (!m_IsInCombat) {
        move();
    }
    combat();
}
void EnemyUnit::render(sf::RenderWindow& window) {
    Unit::render(window); // Call base class render
}
