#ifndef BUILDING_H
#define BUILDING_H

#include <SFML/Graphics.hpp>

class Building {
public:
    Building(const std::string& texturePath, sf::Vector2f position);
    void render(sf::RenderWindow& window);

private:
    sf::Sprite m_Sprite;
    sf::Texture m_Texture;
};

#endif // BUILDING_H
