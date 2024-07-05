#ifndef TURRET_H
#define TURRET_H

#include "Entity.h"
#include "Constants.h"

class Unit;

class Turret : public Entity {
public:
    Turret(float damage, float range, float fireRate, const std::string& texturePath, float x, float y);
    virtual ~Turret() = default;

    virtual void update() override;
    virtual void render(sf::RenderWindow& window) override;
    virtual void upgrade() = 0;
    void flipSprite();

    void attackNearestEnemy(const std::vector<Unit*>& enemyUnits);
    Unit* findNearestEnemyInRange(const std::vector<Unit*>& enemyUnits) const;

    void setRotationSpeed(float speed);
    void rotateTowardsTarget();
    void setTargetPosition(const sf::Vector2f& position);
    void clearTarget();
    void setFlipped(bool flipped) { m_IsFlipped = flipped; }

    bool canFire() const;
    void fire();
    float getDamage() const { return m_Damage; }
    float getRange() const { return m_Range; }

protected:
    float m_Damage;
    float m_Range;
    float m_FireRate;
    bool m_IsFlipped;
    sf::Vector2f m_TargetPosition;
    float m_RotationSpeed;
    bool m_HasTarget;
    sf::Clock m_FireClock;
};

#endif // TURRET_H