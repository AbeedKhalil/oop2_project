#ifndef CASTLE_H
#define CASTLE_H

#include "TextureManager.h"
#include "Turret.h"
#include <vector>

class Castle {
public:
    Castle(const std::string& texturePath, float x, float y);
    ~Castle();

    void render(sf::RenderWindow& window);
    void update();
    void takeDamage(int damage);
    bool isDestroyed() const;
    void setScale(float x, float y);
    sf::Vector2f getPosition() const;
    bool addTurret(int turretType, int position);
    void upgradeTurret(int position);
    bool hasTurret(int position) const;
    int getTurretLevel(int position) const;
    void turretsAttack(const std::vector<Unit*>& enemyUnits);

    void renderHealthBar(sf::RenderWindow& window);

protected:
    sf::Sprite m_Sprite;
    sf::Texture* m_Texture;
    int m_Health;
    Turret* m_Turrets[2];

    sf::Font m_Font;
    sf::Text m_HealthText;
    sf::RectangleShape m_HealthBar;
    sf::RectangleShape m_HealthBarBackground;

    void updateHealthBar();
};

#endif // CASTLE_H