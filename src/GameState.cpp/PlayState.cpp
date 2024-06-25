#include "PlayState.h"
#include "Game.h"
#include "PauseState.h" 
#include "Castle.h"
#include "Shooter1.h"
#include "Tank1.h"


PlayState::PlayState(Game* game) : State(game) {
    m_Font.loadFromFile("MainMenu.otf");
    m_ResourceText.setFont(m_Font);
    m_ResourceText.setCharacterSize(24);
    m_ResourceText.setPosition(10, 10);

    // Load background texture
    m_BackgroundSprite.setTexture(TextureManager::getInstance().getTexture("Play.png"));

    m_Castle = new Castle("Castle.png", 0.0f, 770.0f);  // Player's castle position
    m_EnemyCastle = new EnemyCastle("EnemyCastle.png", 1821.0f, 770.0f);  // Enemy castle position
}

PlayState::~PlayState() {
    for (auto unit : m_PlayerUnits) {
        delete unit;
    }
    for (auto unit : m_EnemyUnits) {
        delete unit;
    }
    delete m_Castle;
    delete m_EnemyCastle;
    m_PlayerUnits.clear();
    m_EnemyUnits.clear();
}

void PlayState::handleInput(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::P) {
            m_Game->pushState(new PauseState(m_Game));
        }
        if (event.key.code == sf::Keyboard::U) {
            if (m_Game->getResources() >= 100) {
                Unit* newUnit = new Shooter1(SPAWN_POSITION_X, SPAWN_POSITION_Y);
                newUnit->setTargetPosition(m_EnemyCastle->getPosition().x, m_EnemyCastle->getPosition().y);
                m_PlayerUnits.push_back(newUnit);
                m_Game->spendResources(100);
            }
        }
        if (event.key.code == sf::Keyboard::T) {
            if (m_Game->getResources() >= 300) {
                Unit* newUnit = new Tank1(SPAWN_POSITION_X, SPAWN_POSITION_Y);
                newUnit->setTargetPosition(m_EnemyCastle->getPosition().x, m_EnemyCastle->getPosition().y);
                m_PlayerUnits.push_back(newUnit);
                m_Game->spendResources(300);
            }
        }
    }
}

void PlayState::update() {
    for (auto& unit : m_PlayerUnits) {
        unit->update();
    }

    adjustUnitPositions();

    for (auto& unit : m_EnemyUnits) {
        unit->update();
    }
    manageUnits();
    updateResources();
    accumulateResources();
}

void PlayState::render(sf::RenderWindow& window) {
    window.draw(m_BackgroundSprite);  // Draw the background
    m_Castle->render(window);  // Render the player's castle first
    m_EnemyCastle->render(window);  // Render the enemy castle
    for (auto& unit : m_PlayerUnits) {
        unit->render(window);
    }
    for (auto& unit : m_EnemyUnits) {
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

void PlayState::manageUnits() {
    for (auto& playerUnit : m_PlayerUnits) {
        bool inCombat = false;
        for (auto& enemyUnit : m_EnemyUnits) {
            if (playerUnit->isInCombatRange(enemyUnit)) {
                playerUnit->engageCombat(enemyUnit);
                enemyUnit->engageCombat(playerUnit);
                inCombat = true;
                break;
            }
        }
        if (!inCombat) {
            playerUnit->engageCombat(nullptr);
        }
    }

    for (auto& enemyUnit : m_EnemyUnits) {
        bool inCombat = false;
        for (auto& playerUnit : m_PlayerUnits) {
            if (enemyUnit->isInCombatRange(playerUnit)) {
                enemyUnit->engageCombat(playerUnit);
                playerUnit->engageCombat(enemyUnit);
                inCombat = true;
                break;
            }
        }
        if (!inCombat) {
            enemyUnit->engageCombat(nullptr);
        }
    }
}

void PlayState::checkCombat(Unit* playerUnit, Unit* enemyUnit) {
    float distance = std::abs(playerUnit->getPosition().x - enemyUnit->getPosition().x);
    if (distance < STOPPING_DISTANCE) {
        playerUnit->engageCombat(enemyUnit);
        enemyUnit->engageCombat(playerUnit);
    }
}

void PlayState::spreadUnitsNearCastle() {
    float castleX = m_EnemyCastle->getPosition().x;
    float spreadCenterX = castleX - CASTLE_ATTACK_RANGE;

    int unitsNearCastle = 0;
    for (auto& unit : m_PlayerUnits) {
        if (unit->isNearCastle()) {
            unit->spreadOut(spreadCenterX, SPREAD_DISTANCE * unitsNearCastle);
            unitsNearCastle++;
        }
    }
}

void PlayState::adjustUnitPositions() {
    for (auto& unit : m_PlayerUnits) {
        unit->adjustPosition(m_PlayerUnits);
    }
}