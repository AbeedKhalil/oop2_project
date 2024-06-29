#include "PlayState.h"
#include "Game.h"
#include "PauseState.h"
#include "Shooter1.h"
#include "Shooter2.h"
#include "Shooter3.h"
#include "Tank1.h"
#include "Tank2.h"
#include "Tank3.h"


PlayState::PlayState(Game* game) : State(game),m_EnemyResources(0), m_EnemySpawnInterval(0.0f) {
    m_Font.loadFromFile("MainMenu.otf");
    m_ResourceText.setFont(m_Font);
    m_ResourceText.setCharacterSize(24);
    m_ResourceText.setPosition(10, 125);
    m_ResourceText.setFillColor(sf::Color(153, 101, 21)); // Dark Gold color

    // Load background texture
    m_BackgroundSprite.setTexture(TextureManager::getInstance().getTexture("Play.png"));

    m_Castle = new Castle("Castle.png", 0.0f, 770.0f);  // Player's castle position
    m_EnemyCastle = new EnemyCastle("EnemyCastle.png", 1821.0f, 770.0f);  // Enemy castle position

    switch (m_Game->getDifficulty()) {
    case Difficulty::NORMAL:
        m_EnemySpawnInterval = 5.0f;
        m_EnemyResources = 1000;
        break;
    case Difficulty::HARD:
        m_EnemySpawnInterval = 3.0f;
        m_EnemyResources = 1500;
        break;
    case Difficulty::IMPOSSIBLE:
        m_EnemySpawnInterval = 2.0f;
        m_EnemyResources = 2000;
        break;
    }

    // Load unit icons
    m_Shooter1Icon.setTexture(TextureManager::getInstance().getTexture("skeleton1-Idle_0.png"));
    m_Shooter2Icon.setTexture(TextureManager::getInstance().getTexture("skeleton6-Idle_0.png"));
    m_Shooter3Icon.setTexture(TextureManager::getInstance().getTexture("skeleton11-Idle_0.png"));
    m_Tank1Icon.setTexture(TextureManager::getInstance().getTexture("skeleton8-Idle_0.png"));
    m_Tank2Icon.setTexture(TextureManager::getInstance().getTexture("skeleton10-Idle_0.png"));
    m_Tank3Icon.setTexture(TextureManager::getInstance().getTexture("skeleton12-Idle_0.png"));

    // Set up icon backgrounds
    sf::Vector2f iconSize(100, 100);
    m_Shooter1Background.setSize(iconSize);
    m_Shooter2Background.setSize(iconSize);
    m_Shooter3Background.setSize(iconSize);
    m_Tank1Background.setSize(iconSize);
    m_Tank2Background.setSize(iconSize);
    m_Tank3Background.setSize(iconSize);

    sf::Color backgroundColor(200, 200, 200);
    m_Shooter1Background.setFillColor(backgroundColor);
    m_Shooter2Background.setFillColor(backgroundColor);
    m_Shooter3Background.setFillColor(backgroundColor);
    m_Tank1Background.setFillColor(backgroundColor);
    m_Tank2Background.setFillColor(backgroundColor);
    m_Tank3Background.setFillColor(backgroundColor);

    // Position icons and backgrounds
    float startX = 10, startY = 10, spacing = 115;
    m_Shooter1Background.setPosition(startX, startY);
    m_Shooter2Background.setPosition(startX + spacing, startY);
    m_Shooter3Background.setPosition(startX + spacing * 2, startY);
    m_Tank1Background.setPosition(startX + spacing * 3, startY);
    m_Tank2Background.setPosition(startX + spacing * 4, startY);
    m_Tank3Background.setPosition(startX + spacing * 5, startY);

    // Position icons (slightly offset from backgrounds)
    float iconOffset = 5;
    m_Shooter1Icon.setPosition(startX + iconOffset + 10.0f, startY + iconOffset + 5.0f);
    m_Shooter2Icon.setPosition(startX + spacing + iconOffset + 10.0f, startY + iconOffset + 5.0f);
    m_Shooter3Icon.setPosition(startX + spacing * 2 + iconOffset + 10.0f, startY + iconOffset);
    m_Tank1Icon.setPosition(startX + spacing * 3 + iconOffset + 5.0f, startY + iconOffset);
    m_Tank2Icon.setPosition(startX + spacing * 4 + iconOffset, startY + iconOffset);
    m_Tank3Icon.setPosition(startX + spacing * 5 + iconOffset - 23.0f, startY + iconOffset - 28.0f);

    // Scale icons to fit in the backgrounds
    float iconScale = 0.75f;
    m_Shooter1Icon.setScale(iconScale, iconScale);
    m_Shooter2Icon.setScale(iconScale, iconScale);
    m_Shooter3Icon.setScale(iconScale, iconScale);
    m_Tank1Icon.setScale(iconScale, iconScale);
    m_Tank2Icon.setScale(iconScale, iconScale);
    m_Tank3Icon.setScale(iconScale * 0.35f, iconScale * 0.35f);
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
    }
    else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(m_Game->getWindow());

        if (m_Shooter1Background.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            spawnUnit(UnitType::SHOOTER_1);
        }
        else if (m_Shooter2Background.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            spawnUnit(UnitType::SHOOTER_2);
        }
        else if (m_Shooter3Background.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            spawnUnit(UnitType::SHOOTER_3);
        }
        else if (m_Tank1Background.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            spawnUnit(UnitType::TANK_1);
        }
        else if (m_Tank2Background.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            spawnUnit(UnitType::TANK_2);
        }
        else if (m_Tank3Background.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            spawnUnit(UnitType::TANK_3);
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

    adjustEnemyUnitPositions();

    checkUnitsAttackingCastle();
    manageUnits();
    updateResources();
    accumulateResources();
    updateEnemyAI();
}


void PlayState::checkUnitsAttackingCastle() {
    // Check player units attacking enemy castle
    for (auto& unit : m_PlayerUnits) {
        float distanceToCastle = std::abs(unit->getPosition().x - m_EnemyCastle->getPosition().x);
        if (distanceToCastle <= CASTLE_ATTACK_DISTANCE) {
            unit->setState(UnitState::FIGHTING);
            unit->attackCastle(m_EnemyCastle);
        }
    }

    // Check enemy units attacking player castle
    for (auto& unit : m_EnemyUnits) {
        float distanceToCastle = std::abs(unit->getPosition().x - m_Castle->getPosition().x);
        if (distanceToCastle <= CASTLE_ATTACK_DISTANCE) {
            unit->setState(UnitState::FIGHTING);
            unit->attackCastle(m_Castle);
        }
    }
}

void PlayState::adjustEnemyUnitPositions() {
    for (auto& unit : m_EnemyUnits) {
        unit->adjustPosition(m_EnemyUnits);
    }
}

void PlayState::render(sf::RenderWindow& window) {
    window.draw(m_BackgroundSprite);  // Draw the background
    m_Castle->render(window);  // Render the player's castle first
    m_EnemyCastle->render(window);  // Render the enemy castle

    // Draw icon backgrounds
    window.draw(m_Shooter1Background);
    window.draw(m_Shooter2Background);
    window.draw(m_Shooter3Background);
    window.draw(m_Tank1Background);
    window.draw(m_Tank2Background);
    window.draw(m_Tank3Background);

    // Draw icons
    window.draw(m_Shooter1Icon);
    window.draw(m_Shooter2Icon);
    window.draw(m_Shooter3Icon);
    window.draw(m_Tank1Icon);
    window.draw(m_Tank2Icon);
    window.draw(m_Tank3Icon);

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
        m_EnemyResources += 15;
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
    if (m_EnemyResources >= SHOOTER_1_WORTH) {
        EnemyUnit* newUnit = createRandomEnemyUnit();
        if (newUnit) {
            newUnit->setTargetPosition(m_Castle->getPosition().x, m_Castle->getPosition().y);
            newUnit->setState(UnitState::MOVING);
            m_EnemyUnits.push_back(newUnit);
        }
    }
}

EnemyUnit* PlayState::createRandomEnemyUnit() {
    int unitType = rand() % 6; // 0-5: Shooter1, Shooter2, Shooter3, Tank1, Tank2, Tank3
    float spawnX = 1920.0f - SPAWN_POSITION_X; // Spawn on the right side
    float spawnY = SPAWN_POSITION_Y;

    switch (unitType) {
    case 0:
        if (m_EnemyResources >= SHOOTER_1_WORTH) {
            m_EnemyResources -= SHOOTER_1_WORTH;
            return new EnemyUnit(SHOOTER_1_SPEED, SHOOTER_1_HEALTH, SHOOTER_1_DAMAGE, SHOOTER_1_ATTACK_RANGE, SHOOTER_1_WORTH, "skeleton1-Idle_0.png", spawnX, spawnY + 25.0f, SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT, SHOOTER_1_SPACING + 250.0f);
        }
        break;
    case 1:
        if (m_EnemyResources >= SHOOTER_2_WORTH) {
            m_EnemyResources -= SHOOTER_2_WORTH;
            return new EnemyUnit(SHOOTER_2_SPEED, SHOOTER_2_HEALTH, SHOOTER_2_DAMAGE, SHOOTER_2_ATTACK_RANGE, SHOOTER_2_WORTH, "skeleton6-Idle_0.png", spawnX, spawnY + 25.0f, SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT, SHOOTER_2_SPACING + 250.0f);
        }
        break;
    case 2:
        if (m_EnemyResources >= SHOOTER_3_WORTH) {
            m_EnemyResources -= SHOOTER_3_WORTH;
            return new EnemyUnit(SHOOTER_3_SPEED, SHOOTER_3_HEALTH, SHOOTER_3_DAMAGE, SHOOTER_3_ATTACK_RANGE, SHOOTER_3_WORTH, "skeleton11-Idle_0.png", spawnX, spawnY + 25.0f, SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT, SHOOTER_3_SPACING + 250.0f);
        }
        break;
    case 3:
        if (m_EnemyResources >= TANK_1_WORTH) {
            m_EnemyResources -= TANK_1_WORTH;
            return new EnemyUnit(TANK_1_SPEED, TANK_1_HEALTH, TANK_1_DAMAGE, TANK_1_ATTACK_RANGE, TANK_1_WORTH, "skeleton8-Idle_0.png", spawnX, spawnY + 25.0f, TANK_TEXTURE_WIDTH * 0.5f, TANK_TEXTURE_HEIGHT * 0.5f, TANK_1_SPACING + 150.0f);
        }
        break;
    case 4:
        if (m_EnemyResources >= TANK_2_WORTH) {
            m_EnemyResources -= TANK_2_WORTH;
            return new EnemyUnit(TANK_2_SPEED, TANK_2_HEALTH, TANK_2_DAMAGE, TANK_2_ATTACK_RANGE, TANK_2_WORTH, "skeleton10-Idle_0.png", spawnX, spawnY + 25.0f, TANK_TEXTURE_WIDTH * 0.5f, TANK_TEXTURE_HEIGHT * 0.5f, TANK_2_SPACING + 150.0f);
        }
        break;
    case 5:
        if (m_EnemyResources >= TANK_3_WORTH) {
            m_EnemyResources -= TANK_3_WORTH;
            return new EnemyUnit(TANK_3_SPEED, TANK_3_HEALTH, TANK_3_DAMAGE, TANK_3_ATTACK_RANGE, TANK_3_WORTH, "skeleton12-Idle_0.png", spawnX, spawnY, TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT, TANK_3_SPACING + 150.0f);
        }
        break;
    }
    return nullptr; // If we can't afford any unit
}

void PlayState::spawnUnit(UnitType type) {
    Unit* newUnit = nullptr;
    int cost = 0;

    switch (type) {
    case UnitType::SHOOTER_1:
        if (m_Game->getResources() >= SHOOTER_1_WORTH) {
            newUnit = new Shooter1(SPAWN_POSITION_X, SPAWN_POSITION_Y);
            cost = SHOOTER_1_WORTH;
        }
        break;
    case UnitType::SHOOTER_2:
        if (m_Game->getResources() >= SHOOTER_2_WORTH) {
            newUnit = new Shooter2(SPAWN_POSITION_X, SPAWN_POSITION_Y);
            cost = SHOOTER_2_WORTH;
        }
        break;
    case UnitType::SHOOTER_3:
        if (m_Game->getResources() >= SHOOTER_3_WORTH) {
            newUnit = new Shooter3(SPAWN_POSITION_X, SPAWN_POSITION_Y);
            cost = SHOOTER_3_WORTH;
        }
        break;
    case UnitType::TANK_1:
        if (m_Game->getResources() >= TANK_1_WORTH) {
            newUnit = new Tank1(SPAWN_POSITION_X, SPAWN_POSITION_Y);
            cost = TANK_1_WORTH;
        }
        break;
    case UnitType::TANK_2:
        if (m_Game->getResources() >= TANK_2_WORTH) {
            newUnit = new Tank2(SPAWN_POSITION_X, SPAWN_POSITION_Y);
            cost = TANK_2_WORTH;
        }
        break;
    case UnitType::TANK_3:
        if (m_Game->getResources() >= TANK_3_WORTH) {
            newUnit = new Tank3(SPAWN_POSITION_X, SPAWN_POSITION_Y);
            cost = TANK_3_WORTH;
        }
        break;
    }

    if (newUnit) {
        newUnit->setTargetPosition(m_EnemyCastle->getPosition().x, m_EnemyCastle->getPosition().y);
        newUnit->setState(UnitState::MOVING);
        m_PlayerUnits.push_back(newUnit);
        m_Game->spendResources(cost);
    }
}

void PlayState::manageUnits() {
    std::vector<Unit*> unitsToRemove;

    // Check for combat and mark dead units for removal
    for (auto& playerUnit : m_PlayerUnits) {
        if (!playerUnit->isAlive()) {
            unitsToRemove.push_back(playerUnit);
            continue;
        }

        bool inCombat = false;
        for (auto& enemyUnit : m_EnemyUnits) {
            if (!enemyUnit->isAlive()) {
                continue;
            }

            float distance = std::abs(playerUnit->getPosition().x - enemyUnit->getPosition().x);
            if (distance <= playerUnit->getAttackRange()) {
                inCombat = true;
                if (playerUnit->getState() != UnitState::FIGHTING) {
                    playerUnit->setState(UnitState::FIGHTING);
                    playerUnit->engageCombat(enemyUnit);
                }
                if (enemyUnit->getState() != UnitState::FIGHTING) {
                    enemyUnit->setState(UnitState::FIGHTING);
                    enemyUnit->engageCombat(playerUnit);
                }
                break;
            }
        }
        if (!inCombat && playerUnit->getState() == UnitState::FIGHTING) {
            playerUnit->setState(UnitState::MOVING);
        }
    }

    for (auto& enemyUnit : m_EnemyUnits) {
        if (!enemyUnit->isAlive()) {
            unitsToRemove.push_back(enemyUnit);
            continue;
        }

        bool inCombat = false;
        for (auto& playerUnit : m_PlayerUnits) {
            if (!playerUnit->isAlive()) {
                continue;
            }

            float distance = std::abs(enemyUnit->getPosition().x - playerUnit->getPosition().x);
            if (distance <= enemyUnit->getAttackRange()) {
                inCombat = true;
                if (enemyUnit->getState() != UnitState::FIGHTING) {
                    enemyUnit->setState(UnitState::FIGHTING);
                    enemyUnit->engageCombat(playerUnit);
                }
                if (playerUnit->getState() != UnitState::FIGHTING) {
                    playerUnit->setState(UnitState::FIGHTING);
                    playerUnit->engageCombat(enemyUnit);
                }
                break;
            }
        }
        if (!inCombat && enemyUnit->getState() == UnitState::FIGHTING) {
            enemyUnit->setState(UnitState::MOVING);
        }
    }

    // Remove dead units and add their worth to the opponent's resources
    for (auto unit : unitsToRemove) {
        auto it = std::find(m_PlayerUnits.begin(), m_PlayerUnits.end(), unit);
        if (it != m_PlayerUnits.end()) {
            m_PlayerUnits.erase(it);
            m_EnemyResources += unit->getGoldWorth();
        }
        else {
            it = std::find(m_EnemyUnits.begin(), m_EnemyUnits.end(), unit);
            if (it != m_EnemyUnits.end()) {
                m_EnemyUnits.erase(it);
                m_Game->addResources(unit->getGoldWorth());
            }
        }
        delete unit;
    }
}

void PlayState::checkCombat(Unit* playerUnit, Unit* enemyUnit) {
    float distance = std::abs(playerUnit->getPosition().x - enemyUnit->getPosition().x);
    if (distance < STOPPING_DISTANCE) {
        playerUnit->engageCombat(enemyUnit);
        enemyUnit->engageCombat(playerUnit);
    }
}

void PlayState::adjustUnitPositions() {
    for (auto& unit : m_PlayerUnits) {
        unit->adjustPosition(m_PlayerUnits);
    }
}