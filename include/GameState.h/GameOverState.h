#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "State.h"

class GameOverState : public State {
public:
    GameOverState(Game* game);
    void handleInput(sf::Event event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Font m_Font;
    sf::Text m_GameOverText;
    sf::Text m_RestartText;
    sf::Text m_ExitText;

    void handleMouseHover(sf::RenderWindow& window);
    void handleMouseClick(sf::RenderWindow& window);
};

#endif // GAMEOVERSTATE_H
