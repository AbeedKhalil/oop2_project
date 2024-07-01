#ifndef TURRET1_H
#define TURRET1_H

#include "Turret.h"

class Turret1 : public Turret {
public:
    Turret1(float x, float y);
    void upgrade() override;
};

#endif // TURRET1_H