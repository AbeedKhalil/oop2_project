#include "Turret1.h"

Turret1::Turret1(float x, float y)
    : Turret(TURRET_1_DAMAGE, TURRET_1_RANGE, TURRET_1_FIRE_RATE, "skeleton1-Shoot_0.png", x, y) {}

void Turret1::upgrade() {
    m_Damage = TURRET_2_DAMAGE;
    m_Range = TURRET_2_RANGE;
    m_FireRate = TURRET_2_FIRE_RATE;
    m_Sprite.setTexture(TextureManager::getInstance().getTexture("skeleton2-Shoot_0.png"));
}