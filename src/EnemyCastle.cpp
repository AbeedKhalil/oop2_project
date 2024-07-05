#include "EnemyCastle.h"
#include "Turret1.h"
#include "Turret2.h"
#include "Turret3.h"

EnemyCastle::EnemyCastle(const std::string& texturePath, float x, float y)
    : Castle(texturePath, x, y) {

    // Adjust turret positions for enemy castle
    float castleWidth = m_Sprite.getGlobalBounds().width;
    m_TurretOffset1X = castleWidth - TURRET_1_OFFSET_X - TURRET_TEXTURE_WIDTH + 60.0f;
    m_TurretOffset2X = castleWidth - TURRET_2_OFFSET_X - TURRET_TEXTURE_WIDTH + 65.0f;
}

void EnemyCastle::takeDamage(int damage) {
    Castle::takeDamage(damage);
}

void EnemyCastle::render(sf::RenderWindow& window) {
    Castle::render(window);
}

void EnemyCastle::update() {
    Castle::update();
}

void EnemyCastle::addTurret(int turretType, int position) {
    float x = m_Sprite.getPosition().x + (position == 0 ? m_TurretOffset1X : m_TurretOffset2X);
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
    }

    // Flip the turret sprite horizontally for enemy turrets
    if (m_Turrets[position]) {
        m_Turrets[position]->flipSprite();
        m_Turrets[position]->setFlipped(true);
    }
}