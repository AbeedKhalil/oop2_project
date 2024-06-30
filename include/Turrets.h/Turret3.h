#ifndef TURRET3_H
#define TURRET3_H

#include "Turret.h"

class Turret3 : public Turret {
public:
    Turret3(float x, float y);
    void upgrade() override;
};

#endif // TURRET3_H