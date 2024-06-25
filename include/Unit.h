#ifndef UNIT_H
#define UNIT_H

#include "Entity.h"

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
    void move();
    void moveToTarget();
    void combat();
};

#endif // UNIT_H
