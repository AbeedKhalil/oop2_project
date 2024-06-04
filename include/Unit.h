#ifndef UNIT_H
#define UNIT_H

#include "Entity.h"

class Unit : public Entity {
public:
    Unit(float speed, int health, const std::string& texturePath);
    virtual void update() override;
    virtual void render(sf::RenderWindow& window) override;
    void takeDamage(int damage);
    bool isAlive() const;

protected:
    sf::Texture m_Texture;
    float m_Speed;
    int m_Health;
};


#endif // UNIT_H
