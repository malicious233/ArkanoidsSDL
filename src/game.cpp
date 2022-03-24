#include "game.h"
#include "leveleditor.h"

// feedback: no buisness logic in this file. Feels more like a config file or a place for some variables/class instances.

Player player;
Projectile projectiles[PROJECTILE_MAX];
Brick* bricks[NUM_BLOCKS] = { nullptr };
int projectileCount = 12;

Sprite player_sprite;
Sprite ball_sprite;