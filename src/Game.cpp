#include "Game.h"
#include "IntroState.h"
#include "GameOverState.h"

Game::Game() : m_Window(sf::VideoMode(1920, 1080), "Age of War 2 Clone"), m_Resources(1500), m_CurrentDifficulty(Difficulty::NORMAL) {
    m_States.push_back(new IntroState(this));
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

State* Game::getCurrentState() {
    if (!m_States.empty()) {
        return m_States.back();
    }
    return nullptr;
}

void Game::clearStates() {
    while (!m_States.empty()) {
        popState();
    }
}

void Game::changeState(State* state) {
    SoundManager::getInstance().stopMusic();
    if (!m_States.empty()) {
        delete m_States.back();
        m_States.pop_back();
    }
    m_States.push_back(state);
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

void Game::setDifficulty(Difficulty difficulty) {
    m_CurrentDifficulty = difficulty;
}

Difficulty Game::getDifficulty() const {
    return m_CurrentDifficulty;
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
