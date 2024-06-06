#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "TextureManager.h"

class Game;

class State {
public:
    virtual ~State() {}
    virtual void handleInput(sf::Event event) = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;

protected:
    State(Game* game) : m_Game(game) {}

    Game* m_Game;
};

#endif // STATE_H
