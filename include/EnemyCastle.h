#ifndef ENEMYCASTLE_H
#define ENEMYCASTLE_H

#include "Castle.h"

class EnemyCastle : public Castle {
public:
    EnemyCastle(const std::string& texturePath, float x, float y);
};

#endif // ENEMYCASTLE_H
