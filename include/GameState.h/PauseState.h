#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "State.h"
#include <SFML/Graphics.hpp>

class PauseState : public State {
public:
    PauseState(Game* game);
    void handleInput(sf::Event event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Font m_Font;
    sf::Text m_PauseText;
};

#endif // PAUSESTATE_H
