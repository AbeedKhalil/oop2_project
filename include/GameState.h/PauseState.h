#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "State.h"

class PauseState : public State {
public:
    PauseState(Game* game);

    void handleInput(sf::Event event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Font m_Font;
    sf::Text m_PauseText;
    sf::Text m_ResumeText;
    sf::Text m_ExitText;
    sf::RenderTexture m_RenderTexture;
    sf::Sprite m_BackgroundSprite;

    // Helper methods for user interaction
    void handleMouseHover(sf::RenderWindow& window);
    void handleMouseClick(sf::RenderWindow& window);
};

#endif // PAUSESTATE_H