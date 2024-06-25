#include "PlayState.h"
#include "Game.h"
#include "PauseState.h"
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

    m_EnemySpawnInterval = 5.0f; // Spawn an enemy unit every 5 seconds
    m_EnemyResources = 500; // Starting enemy resources
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
                newUnit->setState(UnitState::MOVING);
                m_PlayerUnits.push_back(newUnit);
                m_Game->spendResources(100);
            }
        }
        if (event.key.code == sf::Keyboard::T) {
            if (m_Game->getResources() >= 300) {
                Unit* newUnit = new Tank1(SPAWN_POSITION_X, SPAWN_POSITION_Y);
                newUnit->setTargetPosition(m_EnemyCastle->getPosition().x, m_EnemyCastle->getPosition().y);
                newUnit->setState(UnitState::MOVING);
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
    updateEnemyAI();
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

void PlayState::updateEnemyAI() {
    // Accumulate resources for the enemy
    if (m_ResourceClock.getElapsedTime().asSeconds() >= 1.0f) {
        m_EnemyResources += 10; // Add 10 resources every second
        m_ResourceClock.restart();
    }

    // Check if it's time to spawn a new enemy unit
    if (m_EnemySpawnClock.getElapsedTime().asSeconds() >= m_EnemySpawnInterval) {
        spawnEnemyUnit();
        m_EnemySpawnClock.restart();
    }

    // Update enemy units
    for (auto& unit : m_EnemyUnits) {
        unit->update();
    }

    // Manage combat between player and enemy units
    manageUnits();
}

void PlayState::spawnEnemyUnit() {
    if (m_EnemyResources >= 100) {
        EnemyUnit* newUnit = createRandomEnemyUnit();
        if (newUnit) {
            newUnit->setTargetPosition(m_Castle->getPosition().x, m_Castle->getPosition().y);
            newUnit->setState(UnitState::MOVING);
            m_EnemyUnits.push_back(newUnit);
        }
    }
}

EnemyUnit* PlayState::createRandomEnemyUnit() {
    int unitType = rand() % 3; // 0: Shooter1, 1: Shooter2, 2: Tank1
    float spawnX = 1920.0f - SPAWN_POSITION_X; // Spawn on the right side
    float spawnY = SPAWN_POSITION_Y;

    switch (unitType) {
    case 0:
        if (m_EnemyResources >= SHOOTER_1_WORTH) {
            m_EnemyResources -= SHOOTER_1_WORTH;
            return new EnemyUnit(50.0f, SHOOTER_1_HEALTH, SHOOTER_1_DAMAGE, 100.0f, SHOOTER_1_WORTH, "soldier.png", spawnX, spawnY + 25, SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT, SHOOTER_1_SPACING);
        }
        break;
    case 1:
        if (m_EnemyResources >= SHOOTER_2_WORTH) {
            m_EnemyResources -= SHOOTER_2_WORTH;
            return new EnemyUnit(45.0f, SHOOTER_2_HEALTH, SHOOTER_2_DAMAGE, 110.0f, SHOOTER_2_WORTH, "soldier.png", spawnX, spawnY + 25, SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT, SHOOTER_2_SPACING);
        }
        break;
    case 2:
        if (m_EnemyResources >= TANK_1_WORTH) {
            m_EnemyResources -= TANK_1_WORTH;
            return new EnemyUnit(40.0f, TANK_1_HEALTH, TANK_1_DAMAGE, 90.0f, TANK_1_WORTH, "Tank.png", spawnX, spawnY, TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT, TANK_1_SPACING);
        }
        break;
    }
    return nullptr; // If we can't afford any unit
}

void PlayState::manageUnits() {
    for (auto& playerUnit : m_PlayerUnits) {
        for (auto& enemyUnit : m_EnemyUnits) {
            if (playerUnit->isCollidingWith(enemyUnit)) {
                if (playerUnit->getState() != UnitState::FIGHTING) {
                    playerUnit->setState(UnitState::FIGHTING);
                    playerUnit->engageCombat(enemyUnit);
                }
                if (enemyUnit->getState() != UnitState::FIGHTING) {
                    enemyUnit->setState(UnitState::FIGHTING);
                    enemyUnit->engageCombat(playerUnit);
                }
            }
        }
    }

    // Remove dead units and add their worth to the opponent's resources
    auto removeDeadUnits = [this](std::vector<Unit*>& units, bool isPlayerUnits) {
        units.erase(std::remove_if(units.begin(), units.end(),
            [this, isPlayerUnits](Unit* unit) {
                if (unit->getState() == UnitState::DYING) {
                    if (isPlayerUnits) {
                        m_EnemyResources += unit->getGoldWorth();
                    }
                    else {
                        m_Game->addResources(unit->getGoldWorth());
                    }
                    delete unit;
                    return true;
                }
                return false;
            }), units.end());
        };

    removeDeadUnits(m_PlayerUnits, true);
    removeDeadUnits(m_EnemyUnits, false);
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