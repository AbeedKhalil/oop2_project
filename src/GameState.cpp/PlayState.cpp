#include "PlayState.h"
#include "Game.h"
#include "PauseState.h" 
#include "Soldier.h"
#include "Tank.h"
#include "Building.h"

PlayState::PlayState(Game* game) : State(game) {
    m_Units.push_back(new Soldier());  // Create a Soldier unit
    m_Font.loadFromFile("path/to/font.ttf");
    m_ResourceText.setFont(m_Font);
    m_ResourceText.setCharacterSize(24);
    m_ResourceText.setPosition(10, 10);
}

PlayState::~PlayState() {
    for (auto unit : m_Units) {
        delete unit;
    }
    m_Units.clear();
    for (auto building : m_Buildings) {
        delete building;
    }
    m_Buildings.clear();
}

void PlayState::handleInput(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::P) {
            m_Game->pushState(new PauseState(m_Game));
        }
        if (event.key.code == sf::Keyboard::U) {
            if (m_Game->getResources() >= 100) {
                m_Units.push_back(new Soldier());
                m_Game->spendResources(100);
            }
        }
        if (event.key.code == sf::Keyboard::T) {
            if (m_Game->getResources() >= 300) {
                m_Units.push_back(new Tank());
                m_Game->spendResources(300);
            }
        }
        if (event.key.code == sf::Keyboard::B) {
            if (m_Game->getResources() >= 500) {
                m_Buildings.push_back(new Building("path/to/barracks.png", sf::Vector2f(200, 200)));
                m_Game->spendResources(500);
            }
        }
    }
}

void PlayState::update() {
    for (auto& unit : m_Units) {
        unit->update();
    }
    updateResources();
    accumulateResources();
}

void PlayState::render(sf::RenderWindow& window) {
    for (auto& unit : m_Units) {
        unit->render(window);
    }
    for (auto& building : m_Buildings) {
        building->render(window);
    }
    window.draw(m_ResourceText);
}

void PlayState::updateResources() {
    m_ResourceText.setString("Resources: " + std::to_string(m_Game->getResources()));
}

void PlayState::accumulateResources() {
    if (m_ResourceClock.getElapsedTime().asSeconds() >= 1.0f) {
        m_Game->addResources(10); // Add 10 resources every second
        m_ResourceClock.restart();
    }
}
