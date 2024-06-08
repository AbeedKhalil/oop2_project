#ifndef GAME_H
#define GAME_H

#include "State.h"

class Game {
public:
    Game();
    ~Game();
    void run();
    void pushState(State* state);
    void popState();
    int getResources() const;
    void addResources(int amount);
    void spendResources(int amount);
    sf::RenderWindow& getWindow();
    void clearStates();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow m_Window;
    std::vector<State*> m_States;
    int m_Resources;
};

#endif // GAME_H
