#include "WinState.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"

WinState::WinState(Game* game) : State(game) {
    m_Font.loadFromFile("MainMenu.otf");

    m_WinText.setFont(m_Font);
    m_WinText.setString("You Win!");
    m_WinText.setCharacterSize(72);
    m_WinText.setPosition(100, 100);

    m_RestartText.setFont(m_Font);
    m_RestartText.setString("Play Again");
    m_RestartText.setCharacterSize(60);
    m_RestartText.setPosition(850, 220);

    m_ExitText.setFont(m_Font);
    m_ExitText.setString("Exit");
    m_ExitText.setCharacterSize(60);
    m_ExitText.setPosition(955, 340);

    // Load background texture
    m_BackgroundSprite.setTexture(TextureManager::getInstance().getTexture("Win.png"));
}

void WinState::handleInput(sf::Event event) {
    if (event.type == sf::Event::MouseMoved) {
        handleMouseHover(m_Game->getWindow());
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        handleMouseClick(m_Game->getWindow());
    }
}

void WinState::update() {
    // Win state logic (if any)
}

void WinState::render(sf::RenderWindow& window) {
    window.draw(m_BackgroundSprite);  // Draw the background
    window.draw(m_WinText);
    window.draw(m_RestartText);
    window.draw(m_ExitText);
}

void WinState::handleMouseHover(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::FloatRect restartBounds = m_RestartText.getGlobalBounds();
    sf::FloatRect exitBounds = m_ExitText.getGlobalBounds();

    m_RestartText.setFillColor(restartBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) ? sf::Color(0, 90, 0) : sf::Color::White);
    m_ExitText.setFillColor(exitBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) ? sf::Color(0, 90, 0) : sf::Color::White);
}

void WinState::handleMouseClick(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::FloatRect restartBounds = m_RestartText.getGlobalBounds();
    sf::FloatRect exitBounds = m_ExitText.getGlobalBounds();

    if (restartBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        /*m_Game->clearStates();
        m_Game->pushState(new PlayState(m_Game));*/
    }

    if (exitBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        window.close();
    }
}