#include "MenuState.h"
#include "Game.h"
#include "PlayState.h"
#include "HelpState.h"
#include "DifficultySelectState.h"

MenuState::MenuState(Game* game) : State(game) {
    if (!m_Font.loadFromFile("MainMenu.otf")) {
        std::cerr << "ERROR::MENUSTATE::Could not load font\n";
    }

    // Set up the title
    m_Title.setFont(m_Font);
    m_Title.setString("Age of War 2 Clone");
    m_Title.setCharacterSize(72);
    m_Title.setPosition(100, 100);

    // Set up the Start text
    m_StartText.setFont(m_Font);
    m_StartText.setString("Start");
    m_StartText.setCharacterSize(60);
    m_StartText.setPosition(static_cast<float>(930), static_cast<float>(220));
    // Set up the Help text
    m_HelpText.setFont(m_Font);
    m_HelpText.setString("Help");
    m_HelpText.setCharacterSize(60);
    m_HelpText.setPosition(static_cast<float>(955), static_cast<float>(340));

    // Set up the Exit text
    m_ExitText.setFont(m_Font);
    m_ExitText.setString("Exit");
    m_ExitText.setCharacterSize(60);
    m_ExitText.setPosition(static_cast<float>(955), static_cast<float>(460));

    // Load background texture
    m_BackgroundSprite.setTexture(TextureManager::getInstance().getTexture("MainMenu.png"));

    // Load and play background music
    SoundManager::getInstance().loadMusic("MainMenu.ogg");
    SoundManager::getInstance().playMusic();
}

void MenuState::handleInput(sf::Event event) {
    if (event.type == sf::Event::MouseMoved) {
        handleMouseHover(m_Game->getWindow());
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        handleMouseClick(m_Game->getWindow());
    }
}

void MenuState::update() {
    // Update menu
}

void MenuState::render(sf::RenderWindow& window) {
    window.draw(m_BackgroundSprite);  // Draw the background
    window.draw(m_Title);
    window.draw(m_StartText);
    window.draw(m_HelpText);
    window.draw(m_ExitText);
}

void MenuState::handleMouseHover(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::FloatRect startBounds = m_StartText.getGlobalBounds();
    sf::FloatRect helpBounds = m_HelpText.getGlobalBounds();
    sf::FloatRect exitBounds = m_ExitText.getGlobalBounds();

    if (startBounds.contains(mousePos.x, mousePos.y)) {
        m_StartText.setFillColor(sf::Color::Red);
    }
    else {
        m_StartText.setFillColor(sf::Color(120, 0, 0)); // Darker red (Dark Red)
    }

    if (helpBounds.contains(mousePos.x, mousePos.y)) {
        m_HelpText.setFillColor(sf::Color::Red);
    }
    else {
        m_HelpText.setFillColor(sf::Color(120, 0, 0)); // Darker red (Dark Red)
    }

    if (exitBounds.contains(mousePos.x, mousePos.y)) {
        m_ExitText.setFillColor(sf::Color::Red);
    }
    else {
        m_ExitText.setFillColor(sf::Color(120, 0, 0)); // Darker red (Dark Red)
    }
}

void MenuState::handleMouseClick(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::FloatRect startBounds = m_StartText.getGlobalBounds();
    sf::FloatRect helpBounds = m_HelpText.getGlobalBounds();
    sf::FloatRect exitBounds = m_ExitText.getGlobalBounds();

    if (startBounds.contains(mousePos.x, mousePos.y)) {
        m_Game->pushState(new DifficultySelectState(m_Game));
    }

    if (helpBounds.contains(mousePos.x, mousePos.y)) {
        m_Game->pushState(new HelpState(m_Game));
    }

    if (exitBounds.contains(mousePos.x, mousePos.y)) {
        window.close();
    }
}
