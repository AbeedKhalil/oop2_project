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

    // difficulty
    void setDifficulty(Difficulty difficulty);
    Difficulty getDifficulty() const;

    // State management
    void pushState(State* state);
    void popState();
    State* getCurrentState();
    void clearStates();
    void changeState(State* state);

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

    // difficulty
    Difficulty m_CurrentDifficulty;

    sf::RenderWindow m_Window;       // Main render window
    std::vector<State*> m_States;    // Stack of game states
    int m_Resources;                 // Player's resource count
};

#endif // GAME_H