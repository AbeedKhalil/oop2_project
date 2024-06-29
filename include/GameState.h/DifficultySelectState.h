#ifndef DIFFICULTYSELECTSTATE_H
#define DIFFICULTYSELECTSTATE_H

#include "State.h"

class DifficultySelectState : public State {
public:
    DifficultySelectState(Game* game);

    void handleInput(sf::Event event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Font m_Font;
    sf::Text m_Title;
    sf::Text m_NormalText;
    sf::Text m_HardText;
    sf::Text m_ImpossibleText;
    sf::Text m_BackText;
    sf::Sprite m_BackgroundSprite;

    void handleMouseHover(sf::RenderWindow& window);
    void handleMouseClick(sf::RenderWindow& window);
};

#endif // DIFFICULTYSELECTSTATE_H