#ifndef CONSTANTS_H
#define CONSTANTS_H

// game difficulty states
enum class Difficulty {
    NORMAL,
    HARD,
    IMPOSSIBLE
};

// Texture sizes
const float SOLDIER_TEXTURE_WIDTH = 60.0f;
const float SOLDIER_TEXTURE_HEIGHT = 60.0f;
const float TANK_TEXTURE_WIDTH = 120.0f;
const float TANK_TEXTURE_HEIGHT = 120.0f;

// Spawn position
const float SPAWN_POSITION_X = 50.0f;
const float SPAWN_POSITION_Y = 880.0f;

// Game mechanics constants
static constexpr float STOPPING_DISTANCE = 50.0f;
static constexpr float CASTLE_ATTACK_DISTANCE = 20.0f;
static constexpr float UNIT_SPACING = 30.0f;
static constexpr float SPREAD_DISTANCE = 30.0f;

// Turret constants
const int TURRET_COST = 1000;
const int TURRET_UPGRADE_COST = 1500;
const float TURRET_1_DAMAGE = 30.0f;
const float TURRET_2_DAMAGE = 50.0f;
const float TURRET_3_DAMAGE = 80.0f;
const float TURRET_1_RANGE = 200.0f;
const float TURRET_2_RANGE = 250.0f;
const float TURRET_3_RANGE = 300.0f;
const float TURRET_1_FIRE_RATE = 1.0f;  // Shots per second
const float TURRET_2_FIRE_RATE = 1.5f;
const float TURRET_3_FIRE_RATE = 2.0f;

// Turret texture sizes
const float TURRET_TEXTURE_WIDTH = 60.0f;
const float TURRET_TEXTURE_HEIGHT = 60.0f;

// Turret positions relative to castle
const float TURRET_1_OFFSET_X = 75.0f;
const float TURRET_1_OFFSET_Y = 25.0f;
const float TURRET_2_OFFSET_X = 20.0f;
const float TURRET_2_OFFSET_Y = 75.0f;

// Unit health values
const int SHOOTER_1_HEALTH = 500;
const int SHOOTER_2_HEALTH = 550;
const int SHOOTER_3_HEALTH = 330;
const int TANK_1_HEALTH = 380;
const int TANK_2_HEALTH = 450;
const int TANK_3_HEALTH = 950;

// Unit damage values
const int SHOOTER_1_DAMAGE = 50;
const int SHOOTER_2_DAMAGE = 65;
const int SHOOTER_3_DAMAGE = 60;
const int TANK_1_DAMAGE = 70;
const int TANK_2_DAMAGE = 80;
const int TANK_3_DAMAGE = 100;

// Unit gold worth
const int SHOOTER_1_WORTH = 100;
const int SHOOTER_2_WORTH = 200;
const int SHOOTER_3_WORTH = 125;
const int TANK_1_WORTH = 200;
const int TANK_2_WORTH = 300;
const int TANK_3_WORTH = 600;

// Speed for each unit type
const float SHOOTER_1_SPEED = 20.0f;
const float SHOOTER_2_SPEED = 18.0f;
const float SHOOTER_3_SPEED = 22.0f;
const float TANK_1_SPEED = 13.0f;
const float TANK_2_SPEED = 11.0f;
const float TANK_3_SPEED = 18.0f;

// Attack ranges for each unit type
const float SHOOTER_1_ATTACK_RANGE = 150.0f;
const float SHOOTER_2_ATTACK_RANGE = 180.0f;
const float SHOOTER_3_ATTACK_RANGE = 200.0f;
const float TANK_1_ATTACK_RANGE = 50.0f;
const float TANK_2_ATTACK_RANGE = 70.0f;
const float TANK_3_ATTACK_RANGE = 140.0f;

// Unit spacing
const float SHOOTER_1_SPACING = 70.0f;
const float SHOOTER_2_SPACING = 70.0f;
const float SHOOTER_3_SPACING = 70.0f;
const float TANK_1_SPACING = 100.0f;
const float TANK_2_SPACING = 90.0f;
const float TANK_3_SPACING = 120.0f;

// Enemy Castle Spawn
const float ENEMY_CASTLE_X = 1821.0f;
const float ENEMY_CASTLE_Y = 770.0f;


#endif // CONSTANTS_H