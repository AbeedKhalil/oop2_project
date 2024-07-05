#include "Turret.h"
#include "Unit.h"
#include <numbers>

Turret::Turret(float damage, float range, float fireRate, const std::string& texturePath, float x, float y)
    : m_Damage(damage), m_Range(range), m_FireRate(fireRate), m_RotationSpeed(2.0f), m_HasTarget(false), m_IsFlipped(false) {
    m_Sprite.setTexture(TextureManager::getInstance().getTexture(texturePath));
    m_Sprite.setPosition(x, y);
    //m_IsFlipped = false;

    // Adjust this scale factor to make the turrets smaller
    float scaleFactor = 0.3f; // You can adjust this value as needed
    m_Sprite.setScale(scaleFactor, scaleFactor);

    //m_Sprite.setOrigin(m_Sprite.getLocalBounds().width / 2, m_Sprite.getLocalBounds().height / 2);
}
void Turret::update() {
    if (m_HasTarget) {
        rotateTowardsTarget();
    }
}

void Turret::render(sf::RenderWindow& window) {
    window.draw(m_Sprite);
}

void Turret::flipSprite() {
    m_Sprite.setScale(-m_Sprite.getScale().x, m_Sprite.getScale().y);
}

void Turret::setRotationSpeed(float speed) {
    m_RotationSpeed = speed;
}

void Turret::rotateTowardsTarget() {
    if (m_HasTarget) {
        sf::Vector2f direction = m_TargetPosition - m_Sprite.getPosition();

        // Invert the vertical direction for flipped turrets
        if (m_IsFlipped) {
            direction.y = -direction.y;
        }

        float desiredAngle = atan2(direction.y, direction.x) * 180 / std::numbers::pi;

        // Adjust the angle for flipped turrets
        if (m_IsFlipped) {
            desiredAngle = 180 - desiredAngle;
        }

        float currentRotation = m_Sprite.getRotation();
        float angleDifference = desiredAngle - currentRotation;

        // Normalize the angle difference
        while (angleDifference > 180) angleDifference -= 360;
        while (angleDifference < -180) angleDifference += 360;

        // Rotate towards the target
        if (abs(angleDifference) > m_RotationSpeed) {
            if (angleDifference > 0) {
                m_Sprite.rotate(m_RotationSpeed);
            }
            else {
                m_Sprite.rotate(-m_RotationSpeed);
            }
        }
        else {
            m_Sprite.setRotation(desiredAngle);
        }
    }
}

void Turret::setTargetPosition(const sf::Vector2f& position) {
    m_TargetPosition = position;
    m_HasTarget = true;
}

void Turret::clearTarget() {
    m_HasTarget = false;
}

void Turret::attackNearestEnemy(const std::vector<Unit*>& enemyUnits) {
    Unit* target = findNearestEnemyInRange(enemyUnits);
    if (target) {
        setTargetPosition(target->getPosition());
        rotateTowardsTarget();
        if (canFire()) {
            target->takeDamage(m_Damage);
            fire();
        }
    }
    else {
        clearTarget();
    }
}

Unit* Turret::findNearestEnemyInRange(const std::vector<Unit*>& enemyUnits) const {
    Unit* nearestEnemy = nullptr;
    float nearestDistance = m_Range;

    for (Unit* enemy : enemyUnits) {
        if (enemy->isAlive()) {
            float distance = std::sqrt(
                std::pow(m_Sprite.getPosition().x - enemy->getPosition().x, 2) +
                std::pow(m_Sprite.getPosition().y - enemy->getPosition().y, 2)
            );

            if (distance <= m_Range && distance < nearestDistance) {
                nearestEnemy = enemy;
                nearestDistance = distance;
            }
        }
    }

    return nearestEnemy;
}

bool Turret::canFire() const {
    return m_FireClock.getElapsedTime().asSeconds() >= 1.0f / m_FireRate;
}

void Turret::fire() {
    // Implement firing logic here
    m_FireClock.restart();
}