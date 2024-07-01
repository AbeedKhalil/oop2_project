#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "State.h"
#include "UnitManager.h"
#include "EnemyUnit.h"

enum class UnitType {
    SHOOTER_1,
    SHOOTER_2,
    SHOOTER_3,
    TANK_1,
    TANK_2,
    TANK_3
};

class PlayState : public State {
public:
    PlayState(Game* game);
    ~PlayState();

    void handleInput(sf::Event event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    std::vector<Unit*> m_Units;
    Castle* m_Castle;  // Player's castle
    EnemyCastle* m_EnemyCastle;  // Enemy's castle
    std::vector<Unit*> m_PlayerUnits;
    std::vector<Unit*> m_EnemyUnits;
    sf::Font m_Font;
    sf::Text m_ResourceText;
    sf::Sprite m_BackgroundSprite;

    sf::Sprite m_Shooter1Icon, m_Shooter2Icon, m_Shooter3Icon;
    sf::Sprite m_Tank1Icon, m_Tank2Icon, m_Tank3Icon;
    sf::RectangleShape m_Shooter1Background, m_Shooter2Background, m_Shooter3Background;
    sf::RectangleShape m_Tank1Background, m_Tank2Background, m_Tank3Background;

    bool m_CanBuyTurret1;
    bool m_CanBuyTurret2;
    bool m_CanUpgradeTurret1;
    bool m_CanUpgradeTurret2;

    void updateTurretButtons();
    void handleTurretPurchase(int position);
    void handleTurretUpgrade(int position);

    // Initialize player's turret icons
    sf::Sprite m_TurretIcon1, m_TurretIcon2;
    sf::RectangleShape m_TurretBackground1, m_TurretBackground2;

    sf::Clock m_ResourceClock;
    sf::Clock m_EnemySpawnClock;
    float m_EnemySpawnInterval;
    int m_EnemyResources;

    // text up the units 
    sf::Text m_Shooter1;
    sf::Text m_Shooter2;
    sf::Text m_Shooter3;
    sf::Text m_tank1;
    sf::Text m_tank2;
    sf::Text m_tank3;

    
    // Helper methods for game logic
    void updateResources();
    void accumulateResources();
    void manageUnits();
    void checkCombat(Unit* playerUnit, Unit* enemyUnit);
    void checkUnitsAttackingCastle();
    void adjustUnitPositions();

    // Enemy AI methods
    void updateEnemyAI();
    void spawnEnemyUnit();
    void adjustEnemyUnitPositions();
    EnemyUnit* createRandomEnemyUnit();

    void spawnUnit(UnitType type);
};

#endif // PLAYSTATE_H