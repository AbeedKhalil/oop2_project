#ifndef TURRET_H
#define TURRET_H

#include "Entity.h"
#include "Constants.h"

class Turret : public Entity {
public:
    Turret(float damage, float range, float fireRate, const std::string& texturePath, float x, float y);
    virtual ~Turret() = default;

    virtual void update() override;
    virtual void render(sf::RenderWindow& window) override;
    virtual void upgrade() = 0;

    bool canFire() const;
    void fire();
    float getDamage() const { return m_Damage; }
    float getRange() const { return m_Range; }

protected:
    float m_Damage;
    float m_Range;
    float m_FireRate;
    sf::Clock m_FireClock;
};

#endif // TURRET_H