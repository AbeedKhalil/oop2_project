#ifndef CASTLE_H
#define CASTLE_H

#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class Castle {
public:
    Castle(const std::string& texturePath, float x, float y);
    void render(sf::RenderWindow& window);
    void takeDamage(int damage);
    bool isDestroyed() const;
    void setScale(float x, float y);
    sf::Vector2f getPosition() const;  // Add this method

protected:
    sf::Sprite m_Sprite;
    sf::Texture* m_Texture;
    int m_Health;
};

#endif // CASTLE_H
