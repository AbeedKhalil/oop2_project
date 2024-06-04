#include "MenuState.h"
#include "Game.h"
#include "PlayState.h"

MenuState::MenuState(Game* game) : State(game) {
    m_Font.loadFromFile("path/to/font.ttf");
    m_Title.setFont(m_Font);
    m_Title.setString("Age of War 2 Clone");
    m_Title.setCharacterSize(48);
    m_Title.setPosition(200, 200);
}

void MenuState::handleInput(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Enter) {
            m_Game->pushState(new PlayState(m_Game));
        }
    }
}

void MenuState::update() {
    // Update menu
}

void MenuState::render(sf::RenderWindow& window) {
    window.draw(m_Title);
}
