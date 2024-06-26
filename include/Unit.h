#ifndef UNIT_H
#define UNIT_H

#include "Entity.h"
#include <vector>

enum class UnitState {
    IDLE,
    MOVING,
    FIGHTING,
    DYING
};

class Unit : public Entity {
public:
    Unit(float speed, int health, int damage, float attackRange, int goldWorth, const std::string& texturePath, float width, float height, float spacing);
    Unit(float speed, int health, int damage, float attackRange, int goldWorth, const std::string& texturePath, float spawnX, float spawnY, float width, float height, float spacing);

    void update() override;
    void render(sf::RenderWindow& window) override;

    // Combat-related methods
    void takeDamage(int damage);
    bool isAlive() const;
    bool isInCombatRange(const Unit* otherUnit) const;
    void engageCombat(Unit* enemyUnit);
    void attack(Unit* target);

    // Movement-related methods
    void setTargetPosition(float x, float y);
    virtual void move();
    void spreadOut(float centerX, float spreadDistance);
    void adjustPosition(const std::vector<Unit*>& units);

    // Getters
    sf::Vector2f getPosition() const;
    int getGoldWorth() const;
    float getSpacing() const;
    UnitState getState() const;

    // State-related methods
    void setState(UnitState state);
    bool isNearCastle() const;
    bool isCollidingWith(const Unit* other) const;

protected:
    sf::Sprite m_Sprite;
    sf::Texture& m_Texture;
    float m_Speed;
    int m_Health;
    int m_Damage;
    float m_AttackRange;
    int m_GoldWorth;
    Unit* m_EnemyUnit;
    sf::Vector2f m_TargetPosition;
    bool m_IsInCombat;
    float m_Spacing;
    UnitState m_State;
    sf::Clock m_AttackCooldown;

    static constexpr float ATTACK_COOLDOWN = 1.0f; // Attack every 1 second

    void setTextureSize(float width, float height);
    void moveToTarget();
    void combat();
};

#endif // UNIT_H