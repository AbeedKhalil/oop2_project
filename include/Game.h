#ifndef GAME_H
#define GAME_H

#include "State.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Game {
public:
    Game();
    ~Game();

    // Main game loop
    void run();

    // State management
    void pushState(State* state);
    void popState();
    void clearStates();

    // Resource management
    int getResources() const;
    void addResources(int amount);
    void spendResources(int amount);

    // Getter for the render window
    sf::RenderWindow& getWindow();

private:
    // Game loop helper functions
    void processEvents();
    void update();
    void render();

    sf::RenderWindow m_Window;       // Main render window
    std::vector<State*> m_States;    // Stack of game states
    int m_Resources;                 // Player's resource count
};

#endif // GAME_H