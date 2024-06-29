#include "DifficultySelectState.h"
#include "Game.h"
#include "PlayState.h"

DifficultySelectState::DifficultySelectState(Game* game) : State(game) {
    if (!m_Font.loadFromFile("MainMenu.otf")) {
        std::cerr << "ERROR::DIFFICULTYSELECTSTATE::Could not load font\n";
    }

    // Load background texture
    m_BackgroundSprite.setTexture(TextureManager::getInstance().getTexture("MainMenu.png"));

    m_Title.setFont(m_Font);
    m_Title.setString("Age of War 2 Clone");
    m_Title.setCharacterSize(72);
    m_Title.setPosition(static_cast<float>(100.0), static_cast<float>(100.0));

    m_NormalText.setFont(m_Font);
    m_NormalText.setString("Normal");
    m_NormalText.setCharacterSize(60);
    m_NormalText.setPosition(static_cast<float>(895.0), static_cast<float>(220.0));

    m_HardText.setFont(m_Font);
    m_HardText.setString("Hard");
    m_HardText.setCharacterSize(60);
    m_HardText.setPosition(static_cast<float>(950.0), static_cast<float>(340.0));

    m_ImpossibleText.setFont(m_Font);
    m_ImpossibleText.setString("Impossible");
    m_ImpossibleText.setCharacterSize(60);
    m_ImpossibleText.setPosition(static_cast<float>(870.0), static_cast<float>(460.0));

    m_BackText.setFont(m_Font);
    m_BackText.setString("Back");
    m_BackText.setCharacterSize(60);
    m_BackText.setPosition(static_cast<float>(950.0), static_cast<float>(580.0));
}

void DifficultySelectState::handleInput(sf::Event event) {
    if (event.type == sf::Event::MouseMoved) {
        handleMouseHover(m_Game->getWindow());
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        handleMouseClick(m_Game->getWindow());
    }
}

void DifficultySelectState::update() {
    // Update if needed
}

void DifficultySelectState::render(sf::RenderWindow& window) {
    window.draw(m_BackgroundSprite);  // Draw the background
    window.draw(m_Title);
    window.draw(m_NormalText);
    window.draw(m_HardText);
    window.draw(m_ImpossibleText);
    window.draw(m_BackText);
}

void DifficultySelectState::handleMouseHover(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::FloatRect normalBounds = m_NormalText.getGlobalBounds();
    sf::FloatRect hardBounds = m_HardText.getGlobalBounds();
    sf::FloatRect impossibleBounds = m_ImpossibleText.getGlobalBounds();
    sf::FloatRect backBounds = m_BackText.getGlobalBounds();

    if (normalBounds.contains(mousePos.x, mousePos.y)) {
        m_NormalText.setFillColor(sf::Color::Green);
    }
    else {
        m_NormalText.setFillColor(sf::Color(0, 90, 0)); // Darker green
    }

    if (hardBounds.contains(mousePos.x, mousePos.y)) {
        m_HardText.setFillColor(sf::Color::Yellow);
    }
    else {
        m_HardText.setFillColor(sf::Color(120, 120, 0)); // Darker yellow
    }

    if (impossibleBounds.contains(mousePos.x, mousePos.y)) {
        m_ImpossibleText.setFillColor(sf::Color::Red);
    }
    else {
        m_ImpossibleText.setFillColor(sf::Color(130, 0, 0)); // Darker red (Dark Red)
    }

    if (backBounds.contains(mousePos.x, mousePos.y)) {
        m_BackText.setFillColor(sf::Color::White);
    }
    else {
        m_BackText.setFillColor(sf::Color(120, 120, 120)); // Darker white (Dark Gray)
    }
}

void DifficultySelectState::handleMouseClick(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    auto checkClick = [&](const sf::Text& text, Difficulty difficulty) {
        if (text.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            m_Game->setDifficulty(difficulty);
            m_Game->pushState(new PlayState(m_Game));
        }
        };

    checkClick(m_NormalText, Difficulty::NORMAL);
    checkClick(m_HardText, Difficulty::HARD);
    checkClick(m_ImpossibleText, Difficulty::IMPOSSIBLE);

    if (m_BackText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
        m_Game->popState();
    }
}