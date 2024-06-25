#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "State.h"
#include "UnitManager.h"
#include "EnemyCastle.h"
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
    void updateResources();
    void accumulateResources();
    sf::Clock m_ResourceClock;
    void manageUnits();
    void checkCombat(Unit* playerUnit, Unit* enemyUnit);
    void spreadUnitsNearCastle();
    void adjustUnitPositions();

    sf::Clock m_EnemySpawnClock;
    float m_EnemySpawnInterval;
    int m_EnemyResources;

    void updateEnemyAI();
    void spawnEnemyUnit();
    EnemyUnit* createRandomEnemyUnit();
};


#endif // PLAYSTATE_H