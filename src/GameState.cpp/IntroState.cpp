#include "IntroState.h"
#include "Game.h"
#include "MenuState.h"

IntroState::IntroState(Game* game)
    : State(game), m_CurrentImage(0), m_Alpha(0), m_FadingIn(true), m_HoldTime(0) {
    m_IntroSprite1.setTexture(TextureManager::getInstance().getTexture("Names-Intro.png"));
    m_IntroSprite2.setTexture(TextureManager::getInstance().getTexture("Logo-Intro.png"));

    // Load and play background music
    SoundManager::getInstance().loadMusic("end.ogg");
    SoundManager::getInstance().playMusic();
}

void IntroState::handleInput(sf::Event event) {
    if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed) {
        m_Game->changeState(new MenuState(m_Game));
    }
}

void IntroState::update() {
    const float dt = m_Clock.restart().asSeconds();
    const float fadeSpeed = 500.0f; // Adjust this value to change fade speed (lower = slower)
    const float holdDuration = 1.0f; // Duration to hold the image at full opacity

    if (m_FadingIn) {
        m_Alpha += fadeSpeed * dt;
        if (m_Alpha >= 255) {
            m_Alpha = 255;
            m_FadingIn = false;
            m_HoldTime = 0;
        }
    }
    else if (!m_FadingIn && m_HoldTime < holdDuration) {
        m_HoldTime += dt;
    }
    else {
        m_Alpha -= fadeSpeed * dt;
        if (m_Alpha <= 0) {
            m_Alpha = 0;
            m_CurrentImage++;
            if (m_CurrentImage > 1) {
                m_Game->pushState(new MenuState(m_Game));
                return;
            }
            m_FadingIn = true;
        }
    }
}

void IntroState::render(sf::RenderWindow& window) {
    window.clear();

    sf::Sprite* currentSprite = (m_CurrentImage == 0) ? &m_IntroSprite1 : &m_IntroSprite2;
    currentSprite->setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(m_Alpha)));
    window.draw(*currentSprite);

    window.display();
}
