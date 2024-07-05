#ifndef ENTITY_H
#define ENTITY_H

#include "TextureManager.h"
#include "SoundManager.h"
#include "Constants.h"

class Entity {
public:
    virtual ~Entity() {}
    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;

protected:
    sf::Sprite m_Sprite;
};

#endif // ENTITY_H