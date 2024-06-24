#include "PlayState.h"
#include "Game.h"
#include "PauseState.h" 
#include "Soldier.h"
#include "Tank.h"
#include "Castle.h"

PlayState::PlayState(Game* game) : State(game) {
    m_Font.loadFromFile("MainMenu.otf");
    m_ResourceText.setFont(m_Font);
    m_ResourceText.setCharacterSize(24);
    m_ResourceText.setPosition(10, 10);

    // Load background texture
    m_BackgroundSprite.setTexture(TextureManager::getInstance().getTexture("Play.png"));

    m_Castle = new Castle("Castle.png", 0.0f, 750.0f);  // Player's castle position
    m_EnemyCastle = new Castle("EnemyCastle.png", 1803.0f, 750.0f);  // Enemy castle position
}

PlayState::~PlayState() {
    for (auto unit : m_Units) {
        delete unit;
    }
    delete m_Castle;
    m_Units.clear();
}

void PlayState::handleInput(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::P) {
            m_Game->pushState(new PauseState(m_Game));
        }
        if (event.key.code == sf::Keyboard::U) {
            if (m_Game->getResources() >= 100) {
                Unit* newUnit = new Soldier(SPAWN_POSITION_X, SPAWN_POSITION_Y);
                if (!m_Units.empty()) {
                    newUnit->setUnitInFront(m_Units.back());
                }
                m_Units.push_back(newUnit);
                m_Game->spendResources(100);
            }
        }
        if (event.key.code == sf::Keyboard::T) {
            if (m_Game->getResources() >= 300) {
                Unit* newUnit = new Tank(SPAWN_POSITION_X, SPAWN_POSITION_Y);
                if (!m_Units.empty()) {
                    newUnit->setUnitInFront(m_Units.back());
                }
                m_Units.push_back(newUnit);
                m_Game->spendResources(300);
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
    window.draw(m_BackgroundSprite);  // Draw the background
    m_Castle->render(window);
    m_EnemyCastle->render(window);
    for (auto& unit : m_Units) {
        unit->render(window);
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
