#ifndef HELPSTATE_H
#define HELPSTATE_H

#include "State.h"

class HelpState : public State {
public:
    HelpState(Game* game);
    void handleInput(sf::Event event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Font m_Font;
    sf::Text m_HelpText;
    sf::Text m_BackText;
    sf::Sprite m_BackgroundSprite;
};

#endif // HELPSTATE_H
