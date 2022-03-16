#include "game.h"
#include "leveleditor.h"

Player player;
Projectile projectiles[PROJECTILE_MAX];
Brick* bricks[NUM_BLOCKS] = { nullptr };

Sprite player_sprite;
Sprite ball_sprite;