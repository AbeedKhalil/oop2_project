#ifndef ENEMYCASTLE_H
#define ENEMYCASTLE_H

#include "Castle.h"

class EnemyCastle : public Castle {
public:
    EnemyCastle(const std::string& texturePath, float x, float y);
    
    void render(sf::RenderWindow& window);  // Declare the render method
    // Add any enemy-specific methods or overrides here
};

#endif // ENEMYCASTLE_H
