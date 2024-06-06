#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "State.h"

class MenuState : public State {
public:
    MenuState(Game* game);
    void handleInput(sf::Event event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Font m_Font;
    sf::Text m_Title;
    sf::Text m_StartText;
    sf::Text m_HelpText;
    sf::Text m_ExitText;
    sf::Sprite m_BackgroundSprite;

    void handleMouseHover(sf::RenderWindow& window);
    void handleMouseClick(sf::RenderWindow& window);
};

#endif // MENUSTATE_H
