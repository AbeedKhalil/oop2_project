#include "PauseState.h"
#include "Game.h"
#include "MenuState.h"

PauseState::PauseState(Game* game) : State(game) {
    m_Font.loadFromFile("MainMenu.otf");

    // Set up the pause text
    m_PauseText.setFont(m_Font);
    m_PauseText.setString("Game Paused");
    m_PauseText.setCharacterSize(60);
    m_PauseText.setPosition(750, 200);

    // Set up the Resume text
    m_ResumeText.setFont(m_Font);
    m_ResumeText.setString("Resume");
    m_ResumeText.setCharacterSize(60);
    m_ResumeText.setPosition(850, 420);

    // Set up the Exit text
    m_ExitText.setFont(m_Font);
    m_ExitText.setString("Exit to Menu");
    m_ExitText.setCharacterSize(60);
    m_ExitText.setPosition(765, 540);

    // Load background texture
    m_BackgroundSprite.setTexture(TextureManager::getInstance().getTexture("PlayBlur.png"));
}

void PauseState::handleInput(sf::Event event) {
    if (event.type == sf::Event::MouseMoved) {
        handleMouseHover(m_Game->getWindow());
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        handleMouseClick(m_Game->getWindow());
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
        m_Game->popState();  // Resume game
    }
}

void PauseState::update() {
    // Pause state logic
}

void PauseState::render(sf::RenderWindow& window) {
    window.draw(m_BackgroundSprite);  // Draw the backgroun
    window.draw(m_PauseText);
    window.draw(m_ResumeText);
    window.draw(m_ExitText);
}

void PauseState::handleMouseHover(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::FloatRect resumeBounds = m_ResumeText.getGlobalBounds();
    sf::FloatRect exitBounds = m_ExitText.getGlobalBounds();

    if (resumeBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        m_ResumeText.setFillColor(sf::Color::Green);
    }
    else {
        m_ResumeText.setFillColor(sf::Color::White);
    }

    if (exitBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        m_ExitText.setFillColor(sf::Color::Green);
    }
    else {
        m_ExitText.setFillColor(sf::Color::White);
    }
}

void PauseState::handleMouseClick(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::FloatRect resumeBounds = m_ResumeText.getGlobalBounds();
    sf::FloatRect exitBounds = m_ExitText.getGlobalBounds();

    if (resumeBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        m_Game->popState();  // Resume game
    }

    if (exitBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        m_Game->clearStates();  // Exit to menu
        m_Game->pushState(new MenuState(m_Game));  // Push the menu state
    }
}
