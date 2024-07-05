#ifndef INTROSTATE_H
#define INTROSTATE_H

#include "State.h"
#include <SFML/Graphics.hpp>

class IntroState : public State {
public:
    IntroState(Game* game);
    void handleInput(sf::Event event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Sprite m_IntroSprite1;
    sf::Sprite m_IntroSprite2;
    sf::Clock m_Clock;
    int m_CurrentImage;
    float m_Alpha;
    bool m_FadingIn;
    float m_HoldTime;
};

#endif // INTROSTATE_H