#ifndef WINSTATE_H
#define WINSTATE_H

#include "State.h"

class WinState : public State {
public:
    WinState(Game* game);

    void handleInput(sf::Event event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Font m_Font;
    sf::Text m_WinText;
    sf::Text m_RestartText;
    sf::Text m_ExitText;
    sf::Sprite m_BackgroundSprite;

    void handleMouseHover(sf::RenderWindow& window);
    void handleMouseClick(sf::RenderWindow& window);
};

#endif // WINSTATE_H