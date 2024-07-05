#include "GameOverState.h"
#include "Game.h"
#include "DifficultySelectState.h"
#include "PlayState.h"

GameOverState::GameOverState(Game* game) : State(game) {
    m_Font.loadFromFile("MainMenu.otf");

    // Set up the Restart text
    m_RestartText.setFont(m_Font);
    m_RestartText.setString("Restart");
    m_RestartText.setCharacterSize(36);
    m_RestartText.setPosition(895, 805);

    // Set up the Exit text
    m_ExitText.setFont(m_Font);
    m_ExitText.setString("Exit");
    m_ExitText.setCharacterSize(36);
    m_ExitText.setPosition(933, 916);

    // Load background texture
    m_BackgroundSprite.setTexture(TextureManager::getInstance().getTexture("GameOver.png"));

    // Load and play background music
    SoundManager::getInstance().loadMusic("GameOver.ogg");
    SoundManager::getInstance().playMusic();
}

void GameOverState::handleInput(sf::Event event) {
    if (event.type == sf::Event::MouseMoved) {
        handleMouseHover(m_Game->getWindow());
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        handleMouseClick(m_Game->getWindow());
    }
}

void GameOverState::update() {
    // Game over state logic
}

void GameOverState::render(sf::RenderWindow& window) {
    window.draw(m_BackgroundSprite);  // Draw the background
    window.draw(m_RestartText);
    window.draw(m_ExitText);
}

void GameOverState::handleMouseHover(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::FloatRect restartBounds = m_RestartText.getGlobalBounds();
    sf::FloatRect exitBounds = m_ExitText.getGlobalBounds();

    if (restartBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        m_RestartText.setFillColor(sf::Color(120, 120, 120));
    }
    else {
        m_RestartText.setFillColor(sf::Color::White);
    }

    if (exitBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        m_ExitText.setFillColor(sf::Color(120, 120, 120));
    }
    else {
        m_ExitText.setFillColor(sf::Color::White);
    }
}

void GameOverState::handleMouseClick(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::FloatRect restartBounds = m_RestartText.getGlobalBounds();
    sf::FloatRect exitBounds = m_ExitText.getGlobalBounds();

    if (restartBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        //m_Game->clearStates();  // Clear all states
        //m_Game->pushState(new DifficultySelectState(m_Game));  // Restart game
    }

    if (exitBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        window.close();
    }
}
