#ifndef CASTLE_H
#define CASTLE_H

#include "TextureManager.h"
#include "Turret.h"

class Castle {
public:
    Castle(const std::string& texturePath, float x, float y);
    ~Castle();

    // Render the castle on the screen
    void render(sf::RenderWindow& window);

    void update();

    // Handle damage and check castle status
    void takeDamage(int damage);
    bool isDestroyed() const;

    // Adjust castle appearance
    void setScale(float x, float y);

    // Get castle position
    sf::Vector2f getPosition() const;

    bool addTurret(int turretType, int position);
    void upgradeTurret(int position);

    bool hasTurret(int position) const;

    int getTurretLevel(int position) const;

protected:
    sf::Sprite m_Sprite;
    sf::Texture* m_Texture;
    int m_Health;
    Turret* m_Turrets[2];
};

#endif // CASTLE_H