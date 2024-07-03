#include "Castle.h"
#include "Turret1.h"
#include "Turret2.h"
#include "Turret3.h"

Castle::Castle(const std::string& texturePath, float x, float y) : m_Health(8000) {
    m_Texture = &TextureManager::getInstance().getTexture(texturePath);
    m_Sprite.setTexture(*m_Texture);
    m_Sprite.setPosition(x, y);

    float scale = 0.5f;
    m_Sprite.setScale(scale, scale);

    m_Turrets[0] = nullptr;
    m_Turrets[1] = nullptr;

    // Load font
    if (!m_Font.loadFromFile("MainMenu.otf")) {
        // Handle font loading error
    }

    // Set up health text
    m_HealthText.setFont(m_Font);
    m_HealthText.setCharacterSize(20);
    m_HealthText.setFillColor(sf::Color::White);

    // Set up health bar
    m_HealthBar.setFillColor(sf::Color::Green);
    m_HealthBarBackground.setFillColor(sf::Color(100, 100, 100));

    updateHealthBar();
}

Castle::~Castle() {
    for (int i = 0; i < 2; ++i) {
        delete m_Turrets[i];
    }
}

void Castle::render(sf::RenderWindow& window) {
    window.draw(m_Sprite);
    renderHealthBar(window);
    for (int i = 0; i < 2; ++i) {
        if (m_Turrets[i]) {
            m_Turrets[i]->render(window);
        }
    }
}

void Castle::takeDamage(int damage) {
    m_Health -= damage;
    if (m_Health < 0) {
        m_Health = 0;
    }
    updateHealthBar();
}

void Castle::updateHealthBar() {
    float healthPercentage = static_cast<float>(m_Health) / 8000.0f;

    // Update text
    m_HealthText.setString(std::to_string(static_cast<int>(healthPercentage * 100)) + "%");

    // Position text and health bar
    sf::FloatRect textBounds = m_HealthText.getLocalBounds();
    m_HealthText.setOrigin(textBounds.width / 2, textBounds.height / 2);
    m_HealthText.setPosition(m_Sprite.getPosition().x + m_Sprite.getGlobalBounds().width / 2,
        m_Sprite.getPosition().y - 30);

    // Update health bar
    float barWidth = 100.0f;
    float barHeight = 10.0f;
    m_HealthBarBackground.setSize(sf::Vector2f(barWidth, barHeight));
    m_HealthBar.setSize(sf::Vector2f(barWidth * healthPercentage, barHeight));

    m_HealthBarBackground.setPosition(m_Sprite.getPosition().x + m_Sprite.getGlobalBounds().width / 2 - barWidth / 2,
        m_Sprite.getPosition().y - 50);
    m_HealthBar.setPosition(m_HealthBarBackground.getPosition());
}

void Castle::renderHealthBar(sf::RenderWindow& window) {
    window.draw(m_HealthBarBackground);
    window.draw(m_HealthBar);
    window.draw(m_HealthText);
}

bool Castle::isDestroyed() const {
    return m_Health <= 0;
}

void Castle::setScale(float x, float y) {
    m_Sprite.setScale(x, y);
}

sf::Vector2f Castle::getPosition() const {
    return m_Sprite.getPosition();
}

void Castle::update() {
    for (int i = 0; i < 2; ++i) {
        if (m_Turrets[i]) {
            m_Turrets[i]->update();
        }
    }
}

bool Castle::addTurret(int turretType, int position) {
    if (position < 0 || position > 1 || m_Turrets[position] != nullptr) {
        return false;
    }

    float x = m_Sprite.getPosition().x + (position == 0 ? TURRET_1_OFFSET_X : TURRET_2_OFFSET_X);
    float y = m_Sprite.getPosition().y + (position == 0 ? TURRET_1_OFFSET_Y : TURRET_2_OFFSET_Y);

    switch (turretType) {
    case 1:
        m_Turrets[position] = new Turret1(x, y);
        break;
    case 2:
        m_Turrets[position] = new Turret2(x, y);
        break;
    case 3:
        m_Turrets[position] = new Turret3(x, y);
        break;
    default:
        return false;
    }
    return true;
}

void Castle::upgradeTurret(int position) {
    if (position >= 0 && position < 2 && m_Turrets[position]) {
        m_Turrets[position]->upgrade();
    }
}

bool Castle::hasTurret(int position) const {
    if (position < 0 || position > 1) return false;
    return m_Turrets[position] != nullptr;
}

int Castle::getTurretLevel(int position) const {
    if (position < 0 || position > 1 || !m_Turrets[position]) return 0;
    if (dynamic_cast<Turret1*>(m_Turrets[position])) return 1;
    if (dynamic_cast<Turret2*>(m_Turrets[position])) return 2;
    if (dynamic_cast<Turret3*>(m_Turrets[position])) return 3;
    return 0;
}

void Castle::turretsAttack(const std::vector<Unit*>& enemyUnits) {
    for (Turret* turret : m_Turrets) {
        if (turret) {
            turret->update();
            turret->attackNearestEnemy(enemyUnits);
        }
    }
}