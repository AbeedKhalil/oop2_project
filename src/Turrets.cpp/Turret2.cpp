#include "Turret2.h"

Turret2::Turret2(float x, float y)
    : Turret(TURRET_2_DAMAGE, TURRET_2_RANGE, TURRET_2_FIRE_RATE, "skeleton2-Shoot_0.png", x, y) {}

void Turret2::upgrade() {
    m_Damage = TURRET_3_DAMAGE;
    m_Range = TURRET_3_RANGE;
    m_FireRate = TURRET_3_FIRE_RATE;
    m_Sprite.setTexture(TextureManager::getInstance().getTexture("skeleton3-Shoot_0.png"));
}