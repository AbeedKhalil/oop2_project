#ifndef ENEMYCASTLE_H
#define ENEMYCASTLE_H

#include "Castle.h"

class EnemyCastle : public Castle {
public:
    EnemyCastle(const std::string& texturePath, float x, float y);

    void takeDamage(int damage);
    void render(sf::RenderWindow& window);
    void update();
    void addTurret(int turretType, int position);

private:
    float m_TurretOffset1X;
    float m_TurretOffset2X;
};

#endif // ENEMYCASTLE_H