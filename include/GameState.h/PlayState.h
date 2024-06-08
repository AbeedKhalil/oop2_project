#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "State.h"
#include "Unit.h"
#include "UnitManager.h"
#include "Building.h"

class PlayState : public State {
public:
    PlayState(Game* game);
    ~PlayState();
    void handleInput(sf::Event event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;

private:
    std::vector<Unit*> m_Units;
    std::vector<Building*> m_Buildings;
    sf::Font m_Font;
    sf::Text m_ResourceText;
    sf::Sprite m_BackgroundSprite;
    void updateResources();
    void accumulateResources();
    sf::Clock m_ResourceClock;
};


#endif // PLAYSTATE_H
