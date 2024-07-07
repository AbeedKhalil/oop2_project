#include "HelpState.h"
#include "Game.h"
#include "MenuState.h"

HelpState::HelpState(Game* game) : State(game) {
    if (!m_Font.loadFromFile("MainMenu.otf")) {
        std::cerr << "ERROR::HELPSTATE::Could not load font\n";
    }

    // Set up the help text
    m_HelpText.setFont(m_Font);
    m_HelpText.setString("Help Information:\n- Use Mouse to emplace units\n- Press 'P' to pause\n- Press 'Esc' to exit\n\n\n your jop:\n You must attack the enemy army and destroy the enemy castle");
    m_HelpText.setCharacterSize(24);
    m_HelpText.setPosition(50, 50);

    // Set up the back text
    m_BackText.setFont(m_Font);
    m_BackText.setString("Back");
    m_BackText.setCharacterSize(36);
    m_BackText.setPosition(50, 400);

    // Load background texture
    m_BackgroundSprite.setTexture(TextureManager::getInstance().getTexture("Help.png"));
}

void HelpState::handleInput(sf::Event event) {
    if (event.type == sf::Event::MouseMoved) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(m_Game->getWindow());
        sf::FloatRect backBounds = m_BackText.getGlobalBounds();

        if (backBounds.contains(mousePos.x, mousePos.y)) {
            m_BackText.setFillColor(sf::Color::Red);
        }
        else {
            m_BackText.setFillColor(sf::Color::White);
        }
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(m_Game->getWindow());
        sf::FloatRect backBounds = m_BackText.getGlobalBounds();

        if (backBounds.contains(mousePos.x, mousePos.y)) {
            m_Game->popState();
        }
    }
}

void HelpState::update() {
    // Update help state
}

void HelpState::render(sf::RenderWindow& window) {
    window.draw(m_BackgroundSprite);  // Draw the background
    window.draw(m_HelpText);
    window.draw(m_BackText);
}
