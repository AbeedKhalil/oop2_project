#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "State.h"
#include "Unit.h"
#include "UnitManager.h"
#include "Castle.h"

class PlayState : public State {
public:
    PlayState(Game* game);
    ~PlayState();
    void handleInput(sf::Event event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    std::vector<Unit*> m_Units;
    Castle* m_Castle;
    Castle* m_EnemyCastle;
    sf::Font m_Font;
    sf::Text m_ResourceText;
    sf::Sprite m_BackgroundSprite;
    void updateResources();
    void accumulateResources();
    sf::Clock m_ResourceClock;
};


#endif // PLAYSTATE_H
