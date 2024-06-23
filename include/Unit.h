#ifndef UNIT_H
#define UNIT_H

#include "Entity.h"

class Unit : public Entity {
public:
    Unit(float speed, int health, const std::string& texturePath, float width, float height);
    Unit(float speed, int health, const std::string& texturePath, float spawnX, float spawnY, float width, float height);
    void update() override;
    void render(sf::RenderWindow& window) override;
    void takeDamage(int damage);
    bool isAlive() const;
    void setUnitInFront(Unit* unit);

protected:
    sf::Sprite m_Sprite;
    sf::Texture& m_Texture;  // Reference to the texture
    float m_Speed;
    int m_Health;
    Unit* m_UnitInFront;  // Pointer to the unit in front

    void setTextureSize(float width, float height);
    void followUnitInFront();
    void move();
};

#endif // UNIT_H
