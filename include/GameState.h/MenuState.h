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
};

#endif // MENUSTATE_H
