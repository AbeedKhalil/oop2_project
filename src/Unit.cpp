#include "Unit.h"

Unit::Unit(float speed, int health, int damage, float attackRange, int goldWorth, const std::string& texturePath, float width, float height, float spacing)
    : m_Speed(speed), m_Health(health), m_Damage(damage), m_AttackRange(attackRange), m_GoldWorth(goldWorth), m_Texture(TextureManager::getInstance().getTexture(texturePath)), m_EnemyUnit(nullptr), m_IsInCombat(false), m_Spacing(spacing) {
    m_Sprite.setTexture(m_Texture);
    m_Sprite.setPosition(SPAWN_POSITION_X, SPAWN_POSITION_Y);
    setTextureSize(width, height);
}

Unit::Unit(float speed, int health, int damage, float attackRange, int goldWorth, const std::string& texturePath, float spawnX, float spawnY, float width, float height, float spacing)
    : m_Speed(speed), m_Health(health), m_Damage(damage), m_AttackRange(attackRange), m_GoldWorth(goldWorth), m_Texture(TextureManager::getInstance().getTexture(texturePath)), m_EnemyUnit(nullptr), m_IsInCombat(false), m_Spacing(spacing) {
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

void Unit::adjustPosition(const std::vector<Unit*>& units) {
    float myX = m_Sprite.getPosition().x;
    float targetX = myX;

    // Find the unit immediately in front of this one
    Unit* unitInFront = nullptr;
    float minDistance = std::numeric_limits<float>::max();

    for (const auto& unit : units) {
        if (unit == this) continue;
        float otherX = unit->getPosition().x;
        if (otherX > myX && otherX - myX < minDistance) {
            minDistance = otherX - myX;
            unitInFront = unit;
        }
    }

    if (unitInFront) {
        float desiredX = unitInFront->getPosition().x - (this->getSpacing() + unitInFront->getSpacing()) / 2;
        if (myX > desiredX) {
            targetX = desiredX;
        }
    }

    // Smooth movement
    float moveDistance = (targetX - myX) * 0.1f; // Adjust 0.1f for faster/slower adjustment
    m_Sprite.move(moveDistance, 0);
}

float Unit::getSpacing() const
{
    return m_Spacing;
}

void Unit::update() {
    if (!m_IsInCombat) {
        move();
    }
    combat();
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

bool Unit::isInCombatRange(const Unit* otherUnit) const {
    float distance = std::abs(this->getPosition().x - otherUnit->getPosition().x);
    return distance <= m_AttackRange;
}

void Unit::setTargetPosition(float x, float y) {
    m_TargetPosition = sf::Vector2f(x, y);
}

void Unit::engageCombat(Unit* enemyUnit) {
    m_EnemyUnit = enemyUnit;
}

sf::Vector2f Unit::getPosition() const {
    return m_Sprite.getPosition();
}

int Unit::getGoldWorth() const {
    return m_GoldWorth;
}

bool Unit::isNearCastle() const {
    return std::abs(m_Sprite.getPosition().x - m_TargetPosition.x) <= CASTLE_ATTACK_RANGE;
}

void Unit::spreadOut(float centerX, float spreadDistance) {
    float currentX = m_Sprite.getPosition().x;
    float newX = centerX + spreadDistance;

    // Smooth movement towards the spread position
    float moveDistance = (newX - currentX) * 0.1f; // Adjust 0.1f for faster/slower spreading
    m_Sprite.move(moveDistance, 0);
}

void Unit::moveToTarget() {
    sf::Vector2f currentPosition = m_Sprite.getPosition();
    if (currentPosition.x < m_TargetPosition.x) {
        m_Speed = 50.0f;  // Set a base speed
    }
    else {
        m_Speed = 0;  // Stop if at the target position
    }
}

void Unit::combat() {
    if (m_EnemyUnit != nullptr && m_EnemyUnit->isAlive()) {
        if (isInCombatRange(m_EnemyUnit)) {
            m_IsInCombat = true;
            m_EnemyUnit->takeDamage(m_Damage);
            if (!m_EnemyUnit->isAlive()) {
                m_EnemyUnit = nullptr;
                m_IsInCombat = false;
            }
        }
        else {
            m_IsInCombat = false;
        }
    }
    else {
        m_IsInCombat = false;
    }
}

void Unit::move() {
    if (m_Sprite.getPosition().x < m_TargetPosition.x) {
        m_Sprite.move(m_Speed * 0.01f, 0);
    }
}