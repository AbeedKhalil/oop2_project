#include "PauseState.h"
#include "Game.h"

PauseState::PauseState(Game* game) : State(game) {
    m_Font.loadFromFile("path/to/font.ttf");
    m_PauseText.setFont(m_Font);
    m_PauseText.setString("Game Paused\nPress Enter to Resume");
    m_PauseText.setCharacterSize(48);
    m_PauseText.setPosition(200, 200);
}

void PauseState::handleInput(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Enter) {
            m_Game->popState();
        }
    }
}

void PauseState::update() {
    // Pause state update logic
}

void PauseState::render(sf::RenderWindow& window) {
    window.draw(m_PauseText);
}
