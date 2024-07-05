#include "PlayState.h"
#include "Game.h"
#include "PauseState.h"
#include "WinState.h"
#include "GameOverState.h"
#include "Shooter1.h"
#include "Shooter2.h"
#include "Shooter3.h"
#include "Tank1.h"
#include "Tank2.h"
#include "Tank3.h"


PlayState::PlayState(Game* game) : State(game),m_EnemyResources(0), m_EnemySpawnInterval(0.0f), m_CanBuyTurret1(false),
m_CanBuyTurret2(false),
m_CanUpgradeTurret1(false),
m_CanUpgradeTurret2(false), m_FirstTurretAdded(false) {
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

    // Load turret icons
    m_TurretIcon1.setTexture(TextureManager::getInstance().getTexture("skeleton1-Shoot_0.png"));
    m_TurretIcon2.setTexture(TextureManager::getInstance().getTexture("skeleton1-Shoot_0.png"));

    // Load unit icons
    m_Shooter1Icon.setTexture(TextureManager::getInstance().getTexture("skeleton1-Idle_0.png"));
    m_Shooter2Icon.setTexture(TextureManager::getInstance().getTexture("skeleton6-Idle_0.png"));
    m_Shooter3Icon.setTexture(TextureManager::getInstance().getTexture("skeleton11-Idle_0.png"));
    m_Tank1Icon.setTexture(TextureManager::getInstance().getTexture("skeleton8-Idle_0.png"));
    m_Tank2Icon.setTexture(TextureManager::getInstance().getTexture("skeleton10-Idle_0.png"));
    m_Tank3Icon.setTexture(TextureManager::getInstance().getTexture("skeleton12-Idle_0.png"));

    // Set up icon backgrounds
    sf::Vector2f iconSize(110, 110);
    m_Shooter1Background.setSize(iconSize);
    m_Shooter2Background.setSize(iconSize);
    m_Shooter3Background.setSize(iconSize);
    m_Tank1Background.setSize(iconSize);
    m_Tank2Background.setSize(iconSize);
    m_Tank3Background.setSize(iconSize);
    m_TurretBackground1.setSize(iconSize);
    m_TurretBackground2.setSize(iconSize);

    updateIconBackgrounds();

    // Position icons and backgrounds
    float startX = 10, startY = 10, spacing = 115;
    m_Shooter1Background.setPosition(startX, startY);
    m_Shooter2Background.setPosition(startX + spacing, startY);
    m_Shooter3Background.setPosition(startX + spacing * 2, startY);
    m_Tank1Background.setPosition(startX + spacing * 3, startY);
    m_Tank2Background.setPosition(startX + spacing * 4, startY);
    m_Tank3Background.setPosition(startX + spacing * 5, startY);
    m_TurretBackground1.setPosition(startX + spacing * 6, startY);
    m_TurretBackground2.setPosition(startX + spacing * 7, startY);

    // resource positions 
    m_Shooter1.setPosition(startX + 18.0f, startY + 80.0f);
    m_Shooter2.setPosition(startX + spacing + 18.0f, startY + 80.0f);
    m_Shooter3.setPosition(startX + spacing * 2 + 18.0f, startY + 80.0f);
    m_tank1.setPosition(startX + spacing * 3 + 18.0f, startY + 80.0f);
    m_tank2.setPosition(startX + spacing * 4 + 18.0f, startY + 80.0f);
    m_tank3.setPosition(startX + spacing * 5 + 18.0f, startY + 80.0f);
    
    // resources color 
    m_Shooter1.setFillColor(sf::Color::Black);
    m_Shooter2.setFillColor(sf::Color::Black);
    m_Shooter3.setFillColor(sf::Color::Black);
    m_tank1.setFillColor(sf::Color::Black);
    m_tank2.setFillColor(sf::Color::Black);
    m_tank3.setFillColor(sf::Color::Black);

    // resource prices 
    m_Shooter1.setString("(100$)");
    m_Shooter2.setString("(200$)");
    m_Shooter3.setString("(125$)");
    m_tank1.setString("(200$)");
    m_tank2.setString("(300$)");
    m_tank3.setString("(600$)");
    
    // resources characters size

    m_Shooter1.setCharacterSize(20);
    m_Shooter2.setCharacterSize(20);
    m_Shooter3.setCharacterSize(20);
    m_tank1.setCharacterSize(20);
    m_tank2.setCharacterSize(20);
    m_tank3.setCharacterSize(20);

    // resources font
    m_Shooter1.setFont(m_Font);
    m_Shooter2.setFont(m_Font);
    m_Shooter3.setFont(m_Font);
    m_tank1.setFont(m_Font);
    m_tank2.setFont(m_Font);
    m_tank3.setFont(m_Font);


    // Position icons (slightly offset from backgrounds)
    float iconOffset = 5;
    m_Shooter1Icon.setPosition(startX + iconOffset + 10.0f, startY + iconOffset + 5.0f);
    m_Shooter2Icon.setPosition(startX + spacing + iconOffset + 10.0f, startY + iconOffset + 5.0f);
    m_Shooter3Icon.setPosition(startX + spacing * 2 + iconOffset + 10.0f, startY + iconOffset);
    m_Tank1Icon.setPosition(startX + spacing * 3 + iconOffset + 5.0f, startY + iconOffset);
    m_Tank2Icon.setPosition(startX + spacing * 4 + iconOffset, startY + iconOffset);
    m_Tank3Icon.setPosition(startX + spacing * 5 + iconOffset - 23.0f, startY + iconOffset - 28.0f);
    m_TurretIcon1.setPosition(startX + spacing * 6 + iconOffset, startY + iconOffset + 20.0f);
    m_TurretIcon2.setPosition(startX + spacing * 7 + iconOffset, startY + iconOffset + 20.0f);

    // Scale icons to fit in the backgrounds
    float iconScale = 0.75f;
    m_Shooter1Icon.setScale(iconScale, iconScale);
    m_Shooter2Icon.setScale(iconScale, iconScale);
    m_Shooter3Icon.setScale(iconScale, iconScale);
    m_Tank1Icon.setScale(iconScale, iconScale);
    m_Tank2Icon.setScale(iconScale, iconScale);
    m_Tank3Icon.setScale(iconScale * 0.35f, iconScale * 0.35f);
    m_TurretIcon1.setScale(iconScale * 0.5f, iconScale * 0.5f);
    m_TurretIcon2.setScale(iconScale * 0.5f, iconScale * 0.5f);
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
        // Handle turret purchases and upgrades
        if (m_TurretBackground1.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            if (m_CanBuyTurret1) {
                handleTurretPurchase(0);
            }
            else if (m_CanUpgradeTurret1) {
                handleTurretUpgrade(0);
            }
        }
        else if (m_TurretBackground2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            if (m_CanBuyTurret2) {
                handleTurretPurchase(1);
            }
            else if (m_CanUpgradeTurret2) {
                handleTurretUpgrade(1);
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

    if (m_Castle->isDestroyed()) {
        m_Game->pushState(new GameOverState(m_Game));
        return;
    }

    if (m_EnemyCastle->isDestroyed()) {
        m_Game->pushState(new WinState(m_Game));
        return;
    }

    adjustEnemyUnitPositions();

    checkUnitsAttackingCastle();
    manageUnits();

    // Update turret attacks for both player and enemy
    m_Castle->turretsAttack(m_EnemyUnits);
    m_EnemyCastle->turretsAttack(m_PlayerUnits);

    updateResources();
    accumulateResources();
    updateEnemyAI();
    m_Castle->update();
    m_EnemyCastle->update();
    updateTurretButtons();
    updateIconBackgrounds();
}

void PlayState::checkUnitsAttackingCastle() {
    // Check player units attacking enemy castle
    for (auto& unit : m_PlayerUnits) {
        float distanceToCastle = std::abs(unit->getPosition().x - m_EnemyCastle->getPosition().x);
        if (distanceToCastle <= unit->getAttackRange()) {
            unit->setState(UnitState::FIGHTING);
            unit->attackCastle(static_cast<Castle*>(m_EnemyCastle));
        }
    }

    // Check enemy units attacking player castle
    for (auto& unit : m_EnemyUnits) {
        float distanceToCastle = std::abs(unit->getPosition().x - m_Castle->getPosition().x);
        if (distanceToCastle <= unit->getAttackRange()) {
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

    // Draw turret icon backgrounds
    window.draw(m_TurretBackground1);
    window.draw(m_TurretBackground2);

    // Draw icons
    window.draw(m_Shooter1Icon);
    window.draw(m_Shooter2Icon);
    window.draw(m_Shooter3Icon);
    window.draw(m_Tank1Icon);
    window.draw(m_Tank2Icon);
    window.draw(m_Tank3Icon);
  
    // draw resources 
    window.draw(m_Shooter1);
    window.draw(m_Shooter2);
    window.draw(m_Shooter3);
    window.draw(m_tank1);
    window.draw(m_tank2);
    window.draw(m_tank3);
  
    // Draw turret icons
    window.draw(m_TurretIcon1);
    window.draw(m_TurretIcon2);

    for (auto& unit : m_PlayerUnits) {
        unit->render(window);
    }
    for (auto& unit : m_EnemyUnits) {
        unit->render(window);
    }
    window.draw(m_ResourceText);
}

void PlayState::updateTurretButtons() {
    m_CanBuyTurret1 = m_Game->getResources() >= TURRET_COST && !m_Castle->hasTurret(0);
    m_CanBuyTurret2 = m_Game->getResources() >= TURRET_COST && !m_Castle->hasTurret(1);
    m_CanUpgradeTurret1 = m_Game->getResources() >= TURRET_UPGRADE_COST && m_Castle->getTurretLevel(0) < 3;
    m_CanUpgradeTurret2 = m_Game->getResources() >= TURRET_UPGRADE_COST && m_Castle->getTurretLevel(1) < 3;
}

void PlayState::handleTurretPurchase(int position) {
    if (m_Game->getResources() >= TURRET_COST) {
        if (m_Castle->addTurret(1, position)) {
            m_Game->spendResources(TURRET_COST);
        }
    }
}

void PlayState::handleTurretUpgrade(int position) {
    if (m_Game->getResources() >= TURRET_UPGRADE_COST) {
        m_Castle->upgradeTurret(position);
        m_Game->spendResources(TURRET_UPGRADE_COST);
    }
}

void PlayState::updateIconBackgrounds() {
    sf::Color availableColor(200, 200, 200);  // Light gray
    sf::Color unavailableColor(100, 100, 100);  // Dark gray

    m_Shooter1Background.setFillColor(m_Game->getResources() >= SHOOTER_1_WORTH ? availableColor : unavailableColor);
    m_Shooter2Background.setFillColor(m_Game->getResources() >= SHOOTER_2_WORTH ? availableColor : unavailableColor);
    m_Shooter3Background.setFillColor(m_Game->getResources() >= SHOOTER_3_WORTH ? availableColor : unavailableColor);
    m_Tank1Background.setFillColor(m_Game->getResources() >= TANK_1_WORTH ? availableColor : unavailableColor);
    m_Tank2Background.setFillColor(m_Game->getResources() >= TANK_2_WORTH ? availableColor : unavailableColor);
    m_Tank3Background.setFillColor(m_Game->getResources() >= TANK_3_WORTH ? availableColor : unavailableColor);

    // Also update turret backgrounds
    m_TurretBackground1.setFillColor(m_CanBuyTurret1 || m_CanUpgradeTurret1 ? availableColor : unavailableColor);
    m_TurretBackground2.setFillColor(m_CanBuyTurret2 || m_CanUpgradeTurret2 ? availableColor : unavailableColor);
}

void PlayState::updateResources() {
    m_ResourceText.setString(std::to_string(m_Game->getResources()) + "$");
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

    handleEnemyTurretPurchase();

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
            return new EnemyUnit(SHOOTER_1_SPEED, SHOOTER_1_HEALTH - SHOOTER_1_DAMAGE, SHOOTER_1_DAMAGE, SHOOTER_1_ATTACK_RANGE, SHOOTER_1_WORTH, "skeleton1-Idle_0.png", spawnX, spawnY + 25.0f, SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT, SHOOTER_1_SPACING);
        }
        break;
    case 1:
        if (m_EnemyResources >= SHOOTER_2_WORTH) {
            m_EnemyResources -= SHOOTER_2_WORTH;
            return new EnemyUnit(SHOOTER_2_SPEED, SHOOTER_2_HEALTH - SHOOTER_2_DAMAGE, SHOOTER_2_DAMAGE, SHOOTER_2_ATTACK_RANGE, SHOOTER_2_WORTH, "skeleton6-Idle_0.png", spawnX, spawnY + 25.0f, SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT, SHOOTER_2_SPACING);
        }
        break;
    case 2:
        if (m_EnemyResources >= SHOOTER_3_WORTH) {
            m_EnemyResources -= SHOOTER_3_WORTH;
            return new EnemyUnit(SHOOTER_3_SPEED, SHOOTER_3_HEALTH - SHOOTER_3_DAMAGE, SHOOTER_3_DAMAGE, SHOOTER_3_ATTACK_RANGE, SHOOTER_3_WORTH, "skeleton11-Idle_0.png", spawnX, spawnY + 25.0f, SOLDIER_TEXTURE_WIDTH, SOLDIER_TEXTURE_HEIGHT, SHOOTER_3_SPACING);
        }
        break;
    case 3:
        if (m_EnemyResources >= TANK_1_WORTH) {
            m_EnemyResources -= TANK_1_WORTH;
            return new EnemyUnit(TANK_1_SPEED, TANK_1_HEALTH - TANK_1_DAMAGE, TANK_1_DAMAGE, TANK_1_ATTACK_RANGE, TANK_1_WORTH, "skeleton8-Idle_0.png", spawnX, spawnY + 25.0f, TANK_TEXTURE_WIDTH * 0.5f, TANK_TEXTURE_HEIGHT * 0.5f, TANK_1_SPACING);
        }
        break;
    case 4:
        if (m_EnemyResources >= TANK_2_WORTH) {
            m_EnemyResources -= TANK_2_WORTH;
            return new EnemyUnit(TANK_2_SPEED, TANK_2_HEALTH - TANK_2_DAMAGE, TANK_2_DAMAGE, TANK_2_ATTACK_RANGE, TANK_2_WORTH, "skeleton10-Idle_0.png", spawnX, spawnY + 25.0f, TANK_TEXTURE_WIDTH * 0.5f, TANK_TEXTURE_HEIGHT * 0.5f, TANK_2_SPACING);
        }
        break;
    case 5:
        if (m_EnemyResources >= TANK_3_WORTH) {
            m_EnemyResources -= TANK_3_WORTH;
            return new EnemyUnit(TANK_3_SPEED, TANK_3_HEALTH - TANK_3_DAMAGE, TANK_3_DAMAGE, TANK_3_ATTACK_RANGE, TANK_3_WORTH, "skeleton12-Idle_0.png", spawnX, spawnY, TANK_TEXTURE_WIDTH, TANK_TEXTURE_HEIGHT, TANK_3_SPACING);
        }
        break;
    }
    return nullptr; // If we can't afford any unit
}

void PlayState::handleEnemyTurretPurchase() {
    // Check if 30 seconds have passed since the last turret action
    if (m_EnemyTurretTimer.getElapsedTime().asSeconds() >= 30.0f) {
        // Reset the timer
        m_EnemyTurretTimer.restart();

        // If it's the first turret, add it
        if (!m_FirstTurretAdded) {
            if (!m_EnemyCastle->hasTurret(0)) {
                m_EnemyCastle->addTurret(1, 0);
                //m_EnemyResources -= TURRET_COST;
                m_FirstTurretAdded = true;
                return;
            }
        }

        // Randomly decide whether to add a new turret or upgrade an existing one
        bool shouldAddTurret = (rand() % 2 == 0);

        if (shouldAddTurret) {
            // Try to add a new turret
            if (!m_EnemyCastle->hasTurret(0)) {
                m_EnemyCastle->addTurret(1, 0);
                //m_EnemyResources -= TURRET_COST;
            }
            else if (!m_EnemyCastle->hasTurret(1)) {
                m_EnemyCastle->addTurret(1, 1);
                //m_EnemyResources -= TURRET_COST;
            }
        }
        else if (m_EnemyResources) {
            // Try to upgrade a random turret
            int position = rand() % 2;
            if (m_EnemyCastle->hasTurret(position) && m_EnemyCastle->getTurretLevel(position) < 3) {
                m_EnemyCastle->upgradeTurret(position);
                //m_EnemyResources -= TURRET_UPGRADE_COST;
            }
        }
    }
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
        float distanceToEnemyCastle = std::abs(playerUnit->getPosition().x - m_EnemyCastle->getPosition().x);

        if (distanceToEnemyCastle <= playerUnit->getAttackRange()) {
            inCombat = true;
            playerUnit->setState(UnitState::FIGHTING);
            playerUnit->setTargetEnemyCastle(m_EnemyCastle);
        }
        else {
            for (auto& enemyUnit : m_EnemyUnits) {
                if (!enemyUnit->isAlive()) {
                    continue;
                }

                float distance = std::abs(playerUnit->getPosition().x - enemyUnit->getPosition().x);
                if (distance <= playerUnit->getAttackRange()) {
                    inCombat = true;
                    playerUnit->setState(UnitState::FIGHTING);
                    playerUnit->engageCombat(enemyUnit);
                    break;
                }
            }
        }

        if (!inCombat && playerUnit->getState() == UnitState::FIGHTING) {
            playerUnit->setState(UnitState::MOVING);
        }
    }

    // Enemy unit logic
    for (auto& enemyUnit : m_EnemyUnits) {
        if (!enemyUnit->isAlive()) {
            unitsToRemove.push_back(enemyUnit);
            continue;
        }

        bool inCombat = false;
        float distanceToPlayerCastle = std::abs(enemyUnit->getPosition().x - m_Castle->getPosition().x);

        if (distanceToPlayerCastle <= enemyUnit->getAttackRange()) {
            inCombat = true;
            enemyUnit->setState(UnitState::FIGHTING);
            enemyUnit->setTargetCastle(m_Castle);
        }
        else {
            for (auto& playerUnit : m_PlayerUnits) {
                if (!playerUnit->isAlive()) {
                    continue;
                }

                float distance = std::abs(enemyUnit->getPosition().x - playerUnit->getPosition().x);
                if (distance <= enemyUnit->getAttackRange()) {
                    inCombat = true;
                    enemyUnit->setState(UnitState::FIGHTING);
                    enemyUnit->engageCombat(playerUnit);
                    break;
                }
            }
        }

        if (!inCombat && enemyUnit->getState() == UnitState::FIGHTING) {
            enemyUnit->setState(UnitState::MOVING);
        }
    }

    // Remove dead units
    m_PlayerUnits.erase(std::remove_if(m_PlayerUnits.begin(), m_PlayerUnits.end(),
        [this](Unit* unit) {
            if (!unit->isAlive()) {
                m_EnemyResources += unit->getGoldWorth();
                delete unit;
                return true;
            }
            return false;
        }), m_PlayerUnits.end());

    m_EnemyUnits.erase(std::remove_if(m_EnemyUnits.begin(), m_EnemyUnits.end(),
        [this](Unit* unit) {
            if (!unit->isAlive()) {
                m_Game->addResources(unit->getGoldWorth() / 2);
                delete unit;
                return true;
            }
            return false;
        }), m_EnemyUnits.end());

    // Update turrets after removing dead units
    updateTurretAttacks();
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

void PlayState::updateTurretAttacks() {
    if (m_Castle) {
        m_Castle->turretsAttack(m_EnemyUnits);
    }
    if (m_EnemyCastle) {
        m_EnemyCastle->turretsAttack(m_PlayerUnits);
    }
}