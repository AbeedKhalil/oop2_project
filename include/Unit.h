#ifndef UNIT_H
#define UNIT_H

#include "Entity.h"
#include "EnemyCastle.h"
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
    virtual bool isPlayerUnit() const { return true; }

    // Combat-related methods
    void takeDamage(int damage);
    bool isAlive() const;
    bool isInCombatRange(const Unit* otherUnit) const;
    void engageCombat(Unit* enemyUnit);
    void attack(Unit* target);
    void attackCastle(Castle* castle);
    float getAttackRange() const;
    void setTargetCastle(Castle* castle) { m_TargetCastle = castle; }
    void setTargetEnemyCastle(EnemyCastle* enemyCastle) { m_TargetCastle = enemyCastle; }
    virtual void playShootSound();


    // Movement-related methods
    void setTargetPosition(float x, float y);
    virtual void move();
    void spreadOut(float centerX, float spreadDistance);
    void adjustPosition(const std::vector<Unit*>& units);
    void renderHealthBar(sf::RenderWindow& window);

    // Getters
    sf::Vector2f getPosition() const;
    int getGoldWorth() const;
    float getSpacing() const;
    UnitState getState() const;

    // State-related methods
    void setState(UnitState state);
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
    int m_MaxHealth;
    Castle* m_TargetCastle;

    static constexpr float ATTACK_COOLDOWN = 1.0f; // Attack every 1 second

    sf::RectangleShape m_HealthBar;
    sf::RectangleShape m_HealthBarBackground;

    void updateHealthBar();

    void setTextureSize(float width, float height);
    void moveToTarget();
    void combat();
};

#endif // UNIT_H