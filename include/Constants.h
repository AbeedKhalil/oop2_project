#ifndef CONSTANTS_H
#define CONSTANTS_H

// Uniform sizes for textures
const float SOLDIER_TEXTURE_WIDTH = 60.0f;  // Example width for soldier
const float SOLDIER_TEXTURE_HEIGHT = 60.0f; // Example height for soldier

const float TANK_TEXTURE_WIDTH = 120.0f;    // Example width for tank
const float TANK_TEXTURE_HEIGHT = 120.0f;   // Example height for tank

// Spawn position
const float SPAWN_POSITION_X = 50.0f;
const float SPAWN_POSITION_Y = 880.0f;

//-------------------------------tests---------------------------------------------

static constexpr float STOPPING_DISTANCE = 50.0f;

static constexpr float CASTLE_ATTACK_RANGE = 50.0f; // Adjust as needed

static constexpr float UNIT_SPACING = 30.0f; // Adjust as needed

static constexpr float SPREAD_DISTANCE = 30.0f; // Adjust as needed

//---------------------------------------------------------------------------------

// units health
const int SHOOTER_1_HEALTH = 300;
const int SHOOTER_2_HEALTH = 350;
const int SHOOTER_3_HEALTH = 130;
const int TANK_1_HEALTH = 180;
const int TANK_2_HEALTH = 250;
const int TANK_3_HEALTH = 750;

// units damage
const int SHOOTER_1_DAMAGE = 20;
const int SHOOTER_2_DAMAGE = 30;
const int SHOOTER_3_DAMAGE = 30;
const int TANK_1_DAMAGE = 40;
const int TANK_2_DAMAGE = 50;
const int TANK_3_DAMAGE = 50;

// units gold Worth
const int SHOOTER_1_WORTH = 100;
const int SHOOTER_2_WORTH = 200;
const int SHOOTER_3_WORTH = 125;
const int TANK_1_WORTH = 200;
const int TANK_2_WORTH = 300;
const int TANK_3_WORTH = 600;

// units spacing
const float SHOOTER_1_SPACING = 70.0f;
const float SHOOTER_2_SPACING = 45.0f;
const float SHOOTER_3_SPACING = 50.0f;
const float TANK_1_SPACING = 120.0f;
const float TANK_2_SPACING = 80.0f;
const float TANK_3_SPACING = 90.0f;

#endif // CONSTANTS_H
