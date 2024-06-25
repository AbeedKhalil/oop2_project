#ifndef UNIT_H
#define UNIT_H

#include "Entity.h"

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
    void takeDamage(int damage);
    bool isAlive() const;
    bool isInCombatRange(const Unit* otherUnit) const;
    void setTargetPosition(float x, float y);
    void engageCombat(Unit* enemyUnit);
    sf::Vector2f getPosition() const;
    int getGoldWorth() const;
    bool isNearCastle() const;
    void spreadOut(float centerX, float spreadDistance);
    void adjustPosition(const std::vector<Unit*>& units);
    float getSpacing() const;
    virtual void move();
    bool isCollidingWith(const Unit* other) const;
    void setState(UnitState state);
    UnitState getState() const;
    void attack(Unit* target);

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

    void setTextureSize(float width, float height);
    void moveToTarget();
    void combat();

    UnitState m_State;
    sf::Clock m_AttackCooldown;
    static constexpr float ATTACK_COOLDOWN = 1.0f; // Attack every 1 second
};

#endif // UNIT_H