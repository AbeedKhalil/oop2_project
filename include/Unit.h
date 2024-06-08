#ifndef UNIT_H
#define UNIT_H

#include "Entity.h"

class Unit : public Entity {
public:
    Unit(float speed, int health, const std::string& texturePath);
    void update() override;
    void render(sf::RenderWindow& window) override;
    void takeDamage(int damage);
    bool isAlive() const;
    void attack(Unit& target);

protected:
    sf::Sprite m_Sprite;
    sf::Texture& m_Texture;  // Reference to the texture
    float m_Speed;
    int m_Health;
};

#endif // UNIT_H
