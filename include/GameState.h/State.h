#ifndef STATE_H
#define STATE_H

#include <vector>
#include "TextureManager.h"
#include "SoundManager.h"
#include "Constants.h"

class Game;

class State {
public:
    virtual ~State() = default;

    // Pure virtual methods to be implemented by derived states
    virtual void handleInput(sf::Event event) = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;

protected:
    explicit State(Game* game) : m_Game(game) {}

    Game* m_Game;
};

#endif // STATE_H