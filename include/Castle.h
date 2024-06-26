#ifndef CASTLE_H
#define CASTLE_H

#include "TextureManager.h"

class Castle {
public:
    Castle(const std::string& texturePath, float x, float y);

    // Render the castle on the screen
    void render(sf::RenderWindow& window);

    // Handle damage and check castle status
    void takeDamage(int damage);
    bool isDestroyed() const;

    // Adjust castle appearance
    void setScale(float x, float y);

    // Get castle position
    sf::Vector2f getPosition() const;

protected:
    sf::Sprite m_Sprite;
    sf::Texture* m_Texture;
    int m_Health;
};

#endif // CASTLE_H