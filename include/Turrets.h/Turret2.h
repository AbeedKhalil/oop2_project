#ifndef TURRET2_H
#define TURRET2_H

#include "Turret.h"

class Turret2 : public Turret {
public:
    Turret2(float x, float y);
    void upgrade() override;
};

#endif // TURRET2_H