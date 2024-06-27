#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "State.h"
#include "UnitManager.h"
#include "EnemyUnit.h"

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

    sf::Clock m_ResourceClock;
    sf::Clock m_EnemySpawnClock;
    float m_EnemySpawnInterval;
    int m_EnemyResources;

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
};

#endif // PLAYSTATE_H