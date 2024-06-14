#include "Game.h"
#include "MenuState.h"

Game::Game() : m_Window(sf::VideoMode(1920, 1080), "Age of War 2 Clone"), m_Resources(10000) {
    m_States.push_back(new MenuState(this));
}

Game::~Game() {
    clearStates();
}

void Game::run() {
    while (m_Window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::pushState(State* state) {
    m_States.push_back(state);
}

void Game::popState() {
    if (!m_States.empty()) {
        delete m_States.back();
        m_States.pop_back();
    }
}

void Game::clearStates() {
    while (!m_States.empty()) {
        popState();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (m_Window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_Window.close();
        }

        if (!m_States.empty()) {
            m_States.back()->handleInput(event);
        }
    }
}

void Game::update() {
    if (!m_States.empty()) {
        m_States.back()->update();
    }
}

void Game::render() {
    m_Window.clear();
    if (!m_States.empty()) {
        m_States.back()->render(m_Window);
    }
    m_Window.display();
}

int Game::getResources() const {
    return m_Resources;
}

void Game::addResources(int amount) {
    m_Resources += amount;
}

void Game::spendResources(int amount) {
    if (m_Resources >= amount) {
        m_Resources -= amount;
    }
}

sf::RenderWindow& Game::getWindow() {
    return m_Window;
}
